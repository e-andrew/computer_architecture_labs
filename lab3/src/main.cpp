#include <iostream>
#include "command_rules.h"
#include "command_line.h"
#include "syntax_check.h"
#include "execute_command.h"

int main(int argc, char *argv[]) {
    CommandDirector commandDirector = CommandDirector(Rules::LETTERS, Rules::KEY_FLAG, Rules::LONG_KEY_FLAG,
                                                      Rules::PARAMETER_FLAG, Rules::PARAMETER_DELIMITER);

    SyntaxDirector syntaxCheckDirector = SyntaxDirector(Rules::KEY_FLAG, Rules::LONG_KEY_FLAG, Rules::DOUBLE_DELIMITER, Rules::LETTERS,
                                                        Rules::NUMBERS, Rules::SHORT_KEY_NAME, Rules::LONG_KEY_NAME,
                                                        Rules::KEY_PAR_COUNT, Rules::KEY_PAR_TYPE);

    ExecuteDirector executeDirector = ExecuteDirector(Rules::KEY_FLAG, Rules::LONG_KEY_FLAG, Rules::SHORT_KEY_NAME,
            Rules::LONG_KEY_NAME, Rules::KEY_PAR_COUNT, Rules::PARAMETER_DELIMITER);

    if(commandDirector.isCommandExist(argc))
    {
       std::string command = commandDirector.getCommand(argc, argv);
       std::vector<std::vector<std::vector<std::string>>> keys = commandDirector.parseCommand(command);
       if(syntaxCheckDirector.check(keys))
       {
           keys = executeDirector.simplify(keys);
           executeDirector.execute(keys);
       } else {
           std::cout << syntaxCheckDirector.getError() << std::endl;
       }
    }
    return 0;
}
