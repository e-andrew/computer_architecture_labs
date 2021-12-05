#include "key_executor.h"
#include <iostream>

KeyExecutor::KeyExecutor(std::string triggerWord, std::string action, bool isNeedParameter) {
    TRIGGER_WORD = triggerWord;
    ACTION = action;
    IS_NEED_PARAMETER = isNeedParameter;
}

bool KeyExecutor::isTriggerWord(std::string word) {
    return TRIGGER_WORD == word;
}

void KeyExecutor::execute(std::vector<std::string> parameters) {
    std::string output = "========== EXECUTING KEY ==========\n";
    output += "ACTION = " + ACTION + ";\n";
    if(IS_NEED_PARAMETER){
        output += "NEED_PARAMETERS = True;\n";
        output += "PARAMETERS: ";
        for(int i = 0; i < parameters.size(); i++){
            output += parameters[i] + " ";
        }
        output += "\n";
    } else {
        output += "NEED_PARAMETERS = False;\n";
    }
    std::cout << output << std::endl;
}