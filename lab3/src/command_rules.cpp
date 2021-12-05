#include "command_rules.h"

char Rules::KEY_FLAG = '-';
std::string Rules::LONG_KEY_FLAG = "--";
char Rules::PARAMETER_FLAG = '=';
char Rules::PARAMETER_DELIMITER = ',';
char Rules::DOUBLE_DELIMITER = '.';
std::vector<char> Rules::LETTERS = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                             'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                             'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                             'w', 'x', 'y', 'z', '_'};
std::vector<char> Rules::NUMBERS = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', DOUBLE_DELIMITER};
std::vector<char> Rules::SHORT_KEY_NAME = {'h', 'v', 'V', 'L', 'i', 'd', 'I', 'D', 'c', 'C', 's', 'S'};
std::vector<std::string> Rules::LONG_KEY_NAME = {"help", "version", "value", "list", "integer_value", "double_value",
                                                 "integer_list", "double_list", "clean_values", "clean_lists",
                                                 "save_values", "save_lists"};
std::vector<int> Rules::KEY_PAR_COUNT = {0, 0, 1, 3, 1, 1, 3, 3, 0, 0, 0, 0};
std::vector<char> Rules::KEY_PAR_TYPE = {'n', 'n', 'a', 'a', 'i', 'd', 'i', 'd', 'n', 'n', 'n', 'n'};
