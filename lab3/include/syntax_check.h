#include <iostream>
#include "string"
#include "vector"

#ifndef AK_LAB_3_SYNTAX_CHECK_H
#define AK_LAB_3_SYNTAX_CHECK_H


class SyntaxDirector {
private:
    std::basic_string<char> KEY_FLAG;
    std::string LONG_KEY_FLAG;
    char DOUBLE_DELIMITER;
    std::vector<char> LETTERS;
    std::vector<char> NUMBERS;
    std::vector<char> SHORT_KEY_NAME;
    std::vector<std::string> LONG_KEY_NAME;
    std::vector<int> KEY_PAR_COUNT;
    std::vector<char> KEY_PAR_TYPE;

    std::vector<std::string> ERRORS = {
            "IncorrectKeyFlag", "ShortNameOfKeyIsNotGiven", "UnknownSymbolInShortNameOfKey", "UnknownShortNameOfKey",
            "LongNameOfKeyIsNotGiven", "UnknownSymbolInLongNameOfKey", "UnknownLongNameOfKey",
            "GivenParametersButNotGivenDelimiterInLongKey",
            "GivenDelimiterButNotGivenParametersInLongKey", "IncorrectNumberOfParameters",
            "UnknownSymbolInShortKeyParameters",
            "UnknownSymbolInLongKeyParameters", "IncorrectTypeOfParameters"};
    std::string ERROR = "";

private:
    int getIndex(std::vector<char> elements, char key);
    int getIndex(std::vector<std::string> elements, std::string key);
    bool contains(std::vector<char> elements, char symbol);
    bool contains(std::vector<std::string> elements, std::string line);
    bool contains(std::string line, char symbol);
    void setError(int i);
    bool checkKey(std::vector<std::string> key);
    bool checkName(std::vector<std::string> key, std::vector<std::string> name);
    bool checkDelimiter(std::vector<std::string> key, std::vector<std::string> delimiter, std::vector<std::string> parameters);
    bool checkParameters(std::vector<std::string> key, std::vector<std::string> name,
            std::vector<std::string> delimiter, std::vector<std::string> parameters);

public:
    SyntaxDirector(char keyFlag, std::string longKeyFlag, char doubleDelimiter, std::vector<char> letters,
                   std::vector<char> numbers,
                   std::vector<char> shortKeyName, std::vector<std::string> longKeyName, std::vector<int> keyParCount,
                   std::vector<char> keyParType);
    bool check(std::vector<std::vector<std::vector<std::string>>> keys);
    std::string getError();
};

#endif