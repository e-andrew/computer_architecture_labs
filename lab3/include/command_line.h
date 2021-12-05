#include <iostream>
#include "string"
#include "vector"

#ifndef AK_LAB_3_COMMAND_LINE_H
#define AK_LAB_3_COMMAND_LINE_H


class CommandDirector {
private:
    std::vector<char> LETTERS;
    char KEY_FLAG;
    std::string LONG_KEY_FLAG;
    char PARAMETER_FLAG;
    char PARAMETER_DELIMITER;
    int KEY_SIZE = 4;
    int FLAG_SIZE = 1;
    int NAME_SIZE = 1;
    int PARAMETER_FLAG_SIZE = 0;
    int PARAMETER_SIZE = 0;
    std::vector<std::vector<std::vector<std::string>>> parseTree;

private:
    int getIndex(std::string line, char symbol);
    std::string subLine(std::string line, int start, int end);
    bool contains(std::vector<char> elements, char symbol);
    std::vector<std::string> toVector(std::string line);
    std::vector<std::string> emptyVector();
    int entries(std::string line, char symbol);

    void initialiseParseTree(int keyCount);
    std::vector<std::string> getKeys(std::string command);
    std::vector<std::string> splitShortKeys(std::vector<std::string> keys);
    std::vector<std::vector<std::string>> getParts(std::vector<std::string> keys);
    void getParseTree(std::vector<std::vector<std::string>> parts);

public:
    CommandDirector(std::vector<char> letters, char keyFlag, std::string longKeyFlag, char parameterFlag, char parameterDelimiter);
    bool isCommandExist(int argc);
    std::string getCommand(int argc, char *argv[]);
    std::vector<std::vector<std::vector<std::string>>> parseCommand(std::string command);
};

#endif //AK_LAB_3_COMMAND_LINE_H
