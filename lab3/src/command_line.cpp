#include "command_line.h"

CommandDirector::CommandDirector(std::vector<char> letters, char keyFlag, std::string longKeyFlag, char parameterFlag, char parameterDelimiter){
    LETTERS = letters;
    KEY_FLAG = keyFlag;
    LONG_KEY_FLAG = longKeyFlag;
    PARAMETER_FLAG = parameterFlag;
    PARAMETER_DELIMITER = parameterDelimiter;
}

bool CommandDirector::isCommandExist(int argc) {
    return argc > 1;
}

std::string CommandDirector::getCommand(int argc, char **argv) {
    std::string command;
    for (int i = 1; i < argc; i++) {
        command += argv[i];
    }
    return command;
}

int CommandDirector::getIndex(std::string line, char symbol) {
    int index = -1;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == symbol) {
            index = i;
            break;
        }
    }
    return index;
}

std::string CommandDirector::subLine(std::string line, int start, int end) {
    std::string subLine;
    for(int i = start; i < end; i++) subLine += line[i];
    return subLine;
}

bool CommandDirector::contains(std::vector<char> elements, char symbol) {
    bool decision = false;
    for(char element : elements){
        if(symbol == element) {
            decision = true;
            break;
        }
    }
    return decision;
}

std::vector<std::string> CommandDirector::toVector(std::string line) {
    std::vector<std::string> vector;
    vector.resize(1);
    vector[0] = line;
    return vector;
}

std::vector<std::string> CommandDirector::emptyVector() {
    std::vector<std::string> empty;
    empty.resize(0);
    return empty;
}

int CommandDirector::entries(std::string line, char symbol) {
    int count = 0;
    for(char i : line){
        if(i == symbol) count += 1;
    }
    return count;
}

void CommandDirector::initialiseParseTree(int keyCount) {
    parseTree.resize(keyCount);
    for (int i = 0; i < keyCount; i++) {
        parseTree[i].resize(KEY_SIZE);
        parseTree[i][0].resize(FLAG_SIZE);
        parseTree[i][1].resize(NAME_SIZE);
        parseTree[i][2].resize(PARAMETER_FLAG_SIZE);
        parseTree[i][3].resize(PARAMETER_SIZE);
    }
}

std::vector<std::string> CommandDirector::getKeys(std::string command) {
    std::vector<std::string> keys;
    int numberOfKeys = 0;
    std::string key;
    char previousSymbol = KEY_FLAG;
    char actualSymbol;
    for (char symbol : command) {
        actualSymbol = symbol;
        if (actualSymbol == KEY_FLAG && (actualSymbol != previousSymbol || key == LONG_KEY_FLAG)) {
            numberOfKeys += 1;
            keys.resize(numberOfKeys);
            keys[numberOfKeys - 1] = key;
            key = "";
        }
        key += actualSymbol;
        previousSymbol = actualSymbol;
    }
    numberOfKeys += 1;
    keys.resize(numberOfKeys);
    keys[numberOfKeys - 1] = key;
    return keys;
}

std::vector<std::string> CommandDirector::splitShortKeys(std::vector<std::string> keys) {
    int previousKeyLength = keys.size();
    int newKeyLength = 0;
    int length;
    std::vector<std::string> newKeys;
    std::string key;
    std::string subKey;

    for(int i = 0; i < previousKeyLength; i++){
        key = keys[i];
        length = key.length();
        if(length > 2 && key[1] != KEY_FLAG) {
            subKey = key[0];
            for(int j = 1; j < length; j++){
                subKey += key[j];
                if(j + 1 != length && contains(LETTERS, key[j+1])){
                    newKeyLength += 1;
                    newKeys.resize(newKeyLength);
                    newKeys[newKeyLength-1] = subKey;
                    subKey = key[0];
                }
            }
            newKeyLength += 1;
            newKeys.resize(newKeyLength);
            newKeys[newKeyLength-1] = subKey;
        } else {
            newKeyLength += 1;
            newKeys.resize(newKeyLength);
            newKeys[newKeyLength-1] = key;
        }
    }
    return newKeys;
}

std::vector<std::vector<std::string>> CommandDirector::getParts(std::vector<std::string> keys) {
    std::vector<std::vector<std::string>> parts;
    int keyCount = keys.size();
    parts.resize(keyCount);
    std::string key;
    int length;
    int endName;
    int equalIndex;
    std::string name;
    std::string parameters;

    for (int i = 0; i < keyCount; i++) {
        //Initialise variables
        parts[i].resize(KEY_SIZE);
        key = keys[i];
        length = key.length();
        name = "";
        parameters = "";

        //Find parameters
        if (length == 1) {
            parts[i][0] = key[0];
            parts[i][1] = "";
            parts[i][2] = "";
            parts[i][3] = "";
        } else if (length >= 2) {
            //Flag
            if (key[1] == KEY_FLAG) {
                parts[i][0] += key[0];
                parts[i][0] += key[1];
            } else {
                parts[i][0] = key[0];
            }

            //parts[i][0].length() == 1 => SHORT_KEY $$ parts[i][0].length() == 2 => LONG_KEY

            //Delimeter
            equalIndex = getIndex(key, PARAMETER_FLAG);
            if(parts[i][0].length() == 1 || equalIndex == -1) parts[i][2] = ""; else {parts[i][2] = PARAMETER_FLAG;}

            //Name and Parameters
            if(parts[i][0].length() == 2){ //LONG_KEY
                if(equalIndex == -1) {
                    endName = length;
                    parameters = "";
                } else {
                    endName = equalIndex;
                    parameters = subLine(key, equalIndex + 1, length);
                }
                name = subLine(key, 2, endName);
            } else { //SHORT_KEY
                name = key[1];
                parameters = subLine(key, 2, length);
            }
            parts[i][1] = name;
            parts[i][3] = parameters;
        }
    }
    return parts;
}

void CommandDirector::getParseTree(std::vector<std::vector<std::string>> parts) {
    int keyCount = parts.size();
    std::string parametersLine;
    int end;

    for(int i = 0; i < keyCount; i++){
        // Key_Flag
        if(parts[i][0].length() == 0) {parseTree[i][0] = emptyVector();} else {parseTree[i][0] = toVector(parts[i][0]);}
        // Key_Name
        if(parts[i][1].length() == 0) {parseTree[i][1] = emptyVector();} else {parseTree[i][1] = toVector(parts[i][1]);}
        // Flag_Parameter
        if(parts[i][2].length() == 0) {parseTree[i][2] = emptyVector();} else {parseTree[i][2] = toVector(parts[i][2]);}
        // Parameters
        if(parts[i][3].length() == 0) {parseTree[i][3] = emptyVector();} else {

            std::vector<std::string> parameters;
            parametersLine = parts[i][3];
            parameters.resize(entries(parametersLine, PARAMETER_DELIMITER) + 1);

            int j = 0;
            while(parametersLine.length() != 0){
                end = getIndex(parametersLine, PARAMETER_DELIMITER);
                if(end == -1) {
                    parameters[j] = parametersLine;
                    break;
                }
                parameters[j] = subLine(parametersLine, 0, end);
                parametersLine = subLine(parametersLine, end + 1, parametersLine.length());
                j++;
            }
            parseTree[i][3] = parameters;
        }
    }
}

std::vector<std::vector<std::vector<std::string>>> CommandDirector::parseCommand(std::string command) {
    std::vector<std::string> keys;
    std::vector<std::vector<std::string>> parts;

    keys = getKeys(std::move(command));
    keys = splitShortKeys(keys);
    parts = getParts(keys);
    initialiseParseTree(parts.size());
    getParseTree(parts);
    return parseTree;
}
