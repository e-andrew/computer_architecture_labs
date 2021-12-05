#include <iostream>
#include "string"
#include "vector"
#include "key_executor.h"

#ifndef AK_LAB_3_EXECUTE_COMMAND_H
#define AK_LAB_3_EXECUTE_COMMAND_H


class ExecuteDirector {
private:
    std::basic_string<char> KEY_FLAG;
    std::string LONG_KEY_FLAG;
    std::vector<char> SHORT_KEY_NAME;
    std::vector<std::string> LONG_KEY_NAME;
    std::vector<int> KEY_PAR_COUNT;
    char PARAMETER_DELIMITER;

    std::vector<KeyExecutor> EXECUTOR_OF_KEY;
    int getIndex(std::vector<char> elements, char element);
    int getIndex(std::vector<std::string> elements, std::string element);
    bool isNeedParameters(int count);
public:
    explicit ExecuteDirector(char keyFlag, std::string longKeyFlag, std::vector<char> shortKeyName,
            std::vector<std::string> longKeyName, std::vector<int> keyParCount, char parameterDelimiter);
    std::vector<std::vector<std::vector<std::string>>> simplify(std::vector<std::vector<std::vector<std::string>>> keys);
    void execute(std::vector<std::vector<std::vector<std::string>>> keys);
};

#endif
