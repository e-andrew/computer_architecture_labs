#include "vector"
#include "string"

#ifndef AK_LAB_3_COMMAND_RULES_H
#define AK_LAB_3_COMMAND_RULES_H
class Rules{
public:
    static char KEY_FLAG;
    static std::string LONG_KEY_FLAG;
    static char PARAMETER_FLAG;
    static char PARAMETER_DELIMITER;
    static char DOUBLE_DELIMITER;
    static std::vector<char> LETTERS;
    static std::vector<char> NUMBERS;
    static std::vector<char> SHORT_KEY_NAME;
    static std::vector<std::string> LONG_KEY_NAME;
    static std::vector<int> KEY_PAR_COUNT;
    static std::vector<char> KEY_PAR_TYPE;
};
#endif // AK_LAB_3_COMMAND_RULES_H
