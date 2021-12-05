#include "syntax_check.h"

SyntaxDirector::SyntaxDirector(char keyFlag, std::string longKeyFlag, char doubleDelimiter, std::vector<char> letters,
                               std::vector<char> numbers, std::vector<char> shortKeyName,
                               std::vector<std::string> longKeyName, std::vector<int> keyParCount,
                               std::vector<char> keyParType) {
    KEY_FLAG = keyFlag;
    LONG_KEY_FLAG = longKeyFlag;
    DOUBLE_DELIMITER = doubleDelimiter;
    LETTERS = letters;
    NUMBERS = numbers;
    SHORT_KEY_NAME = shortKeyName;
    LONG_KEY_NAME = longKeyName;
    KEY_PAR_COUNT = keyParCount;
    KEY_PAR_TYPE = keyParType;
}

int SyntaxDirector::getIndex(std::vector<char> elements, char key) {
    int index = -1;
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == key) {
            index = i;
            break;
        }
    }
    return index;
}

int SyntaxDirector::getIndex(std::vector<std::string> elements, std::string key) {
    int index = -1;
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == key) {
            index = i;
            break;
        }
    }
    return index;
}

bool SyntaxDirector::contains(std::vector<char> elements, char symbol) {
    bool decision = false;
    for(char element : elements){
        if(symbol == element) {
            decision = true;
            break;
        }
    }
    return decision;
}

bool SyntaxDirector::contains(std::vector<std::string> elements, std::string line) {
    bool decision = false;
    for(std::string element : elements){
        if(line == element) {
            decision = true;
            break;
        }
    }
    return decision;
}

bool SyntaxDirector::contains(std::string line, char symbol) {
    bool decision = false;
    for(char element : line){
        if(symbol == element) {
            decision = true;
            break;
        }
    }
    return decision;
}

void SyntaxDirector::setError(int i) {ERROR = "ERROR: " + ERRORS[i];}

std::string SyntaxDirector::getError() { return ERROR; }

bool SyntaxDirector::checkKey(std::vector<std::string> key) {
    bool decision = true;
    std::string unpackedKey = key[0];
    if(unpackedKey != KEY_FLAG && unpackedKey != LONG_KEY_FLAG) {
        decision = false;
        setError(0);
    }
    return decision;
}

bool SyntaxDirector::checkName(std::vector<std::string> key, std::vector<std::string> name) {
    bool decision = true;
    bool isShort = key[0] == KEY_FLAG;
    bool isNameEmpty = name.empty();
    std::string unpackedName;

    if(isNameEmpty && isShort) {
        decision = false;
        setError(1);
    } else if(isNameEmpty) {
        decision = false;
        setError(4);
    } else {
        unpackedName = name[0];
    }

    if(decision) {
        for (char symbol : unpackedName) {
            if (!contains(LETTERS, symbol)) {
                decision = false;
                if (isShort) { setError(2); } else { setError(5); }
                break;
            }
        }
    }

    if(decision){
        if(isShort && !contains(SHORT_KEY_NAME, unpackedName[0])){
            decision = false;
            setError(3);
        } else if (!isShort && !contains(LONG_KEY_NAME, unpackedName)){
            decision = false;
            setError(6);
        }
    }
    return decision;
}

bool SyntaxDirector::checkDelimiter(std::vector<std::string> key, std::vector<std::string> delimiter, std::vector<std::string> parameters) {
    bool decision = true;
    std::string unpackedKey = key[0];
    bool isDelimiterExists = !delimiter.empty();
    bool isParametersExists = !parameters.empty();

    if(unpackedKey == LONG_KEY_FLAG) {
        if(!isDelimiterExists && isParametersExists){
            decision = false;
            setError(7);
        } else if (isDelimiterExists && !isParametersExists) {
            decision = false;
            setError(8);
        }
    }
    return decision;
}

bool SyntaxDirector::checkParameters(std::vector<std::string> key, std::vector<std::string> name,
                                     std::vector<std::string> delimiter, std::vector<std::string> parameters) {
    bool decision = true;
    bool isShortKey = key[0] == KEY_FLAG;
    std::string unpackedName = name[0];
    int size = parameters.size();
    int index;
    char requiredType;
    char type;


    if(isShortKey) {
        index = getIndex(SHORT_KEY_NAME, unpackedName[0]);
    } else {
        index = getIndex(LONG_KEY_NAME, unpackedName);
    }

    requiredType = KEY_PAR_TYPE[index];

    if(size != KEY_PAR_COUNT[index]){
        decision = false;
        setError(9);
    }

    if(decision){
        for(int i = 0; i < size; i++){
            char previousSymbol = 0;
            char actualSymbol;
            for(int j = 0; j < parameters[i].length(); j++){
                actualSymbol = parameters[i][j];
                if(!contains(NUMBERS, actualSymbol)){
                    decision = false;
                    if(isShortKey) {
                        setError(10);
                    } else {
                        setError(11);
                    }
                    break;
                }

                if(actualSymbol == DOUBLE_DELIMITER && actualSymbol == previousSymbol){
                    decision = false;
                    if(isShortKey) {
                        setError(10);
                    } else {
                        setError(11);
                    }
                    break;
                }
                previousSymbol = actualSymbol;
            }

            if(requiredType != 'a'){
                if(contains(parameters[i], DOUBLE_DELIMITER)) {
                    type = 'd';
                } else {
                    type = 'i';
                }

                if(type != requiredType) {
                    decision = false;
                    setError(12);
                }
            }

            if(!decision) break;
        }
    }

    return decision;
}

bool SyntaxDirector::check(std::vector<std::vector<std::vector<std::string>>> keys) {
    bool decision = true;
    for(int i = 0; i < keys.size(); i++){
        decision = checkKey(keys[i][0]) && checkName(keys[i][0], keys[i][1]) &&
                   checkDelimiter(keys[i][0], keys[i][2], keys[i][3]) &&
                   checkParameters(keys[i][0], keys[i][1], keys[i][2], keys[i][3]);
        if(!decision) break;
    }
    return decision;
}
