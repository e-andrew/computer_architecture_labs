#include "execute_command.h"
#include "key_executor.h"

int ExecuteDirector::getIndex(std::vector<char> elements, char element) {
    int index = -1;
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == element) {
            index = i;
            break;
        }
    }
    return index;
}

int ExecuteDirector::getIndex(std::vector<std::string> elements, std::string element) {
    int index = -1;
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i] == element) {
            index = i;
            break;
        }
    }
    return index;
}

bool ExecuteDirector::isNeedParameters(int count) {
    return count != 0;
}

//Initialise executors.
ExecuteDirector::ExecuteDirector(char keyFlag, std::string longKeyFlag, std::vector<char> shortKeyName,
                                 std::vector<std::string> longKeyName, std::vector<int> keyParCount, char parameterDelimiter) {
    KEY_FLAG = keyFlag;
    LONG_KEY_FLAG = longKeyFlag;
    SHORT_KEY_NAME = shortKeyName;
    LONG_KEY_NAME = longKeyName;
    KEY_PAR_COUNT = keyParCount;
    PARAMETER_DELIMITER = parameterDelimiter;
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[0], "HELP", isNeedParameters(KEY_PAR_COUNT[0])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[1], "VERSION", isNeedParameters(KEY_PAR_COUNT[1])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[2], "VALUE", isNeedParameters(KEY_PAR_COUNT[2])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[3], "LIST", isNeedParameters(KEY_PAR_COUNT[3])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[4], "INTEGER_VALUE", isNeedParameters(KEY_PAR_COUNT[4])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[5], "DOUBLE_VALUE", isNeedParameters(KEY_PAR_COUNT[5])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[6], "INTEGER_LIST", isNeedParameters(KEY_PAR_COUNT[6])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[7], "DOUBLE_LIST", isNeedParameters(KEY_PAR_COUNT[7])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[8], "CLEAN_VALUES", isNeedParameters(KEY_PAR_COUNT[8])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[9], "CLEAN_LISTS", isNeedParameters(KEY_PAR_COUNT[9])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[10], "SAVE_VALUES", isNeedParameters(KEY_PAR_COUNT[10])));
    EXECUTOR_OF_KEY.emplace_back(KeyExecutor(LONG_KEY_NAME[11], "SAVE_LISTS", isNeedParameters(KEY_PAR_COUNT[11])));
}

std::vector<std::vector<std::vector<std::string>>>
ExecuteDirector::simplify(std::vector<std::vector<std::vector<std::string>>> keys) {
    std::vector<std::string> packedDelimiter = {"0"};
    packedDelimiter[0] = PARAMETER_DELIMITER;
    int keyIndex;
    std::vector<std::vector<std::vector<std::string>>> newKeys;
    int newKeysSize = 0;

    for(auto & key : keys){
        if(key[0][0] == KEY_FLAG) {
            key[0][0] = LONG_KEY_FLAG;
            keyIndex = getIndex(SHORT_KEY_NAME, key[1][0][0]);
            key[1][0] = LONG_KEY_NAME[keyIndex];
            if(KEY_PAR_COUNT[keyIndex] != 0) { key[2] = packedDelimiter;}
        }

        //TO_DO parameters not compare
        if(newKeysSize == 0){
            newKeysSize += 1;
            newKeys.resize(newKeysSize);
            newKeys[newKeysSize-1] = key;
        } else {
            for(int j = 0; j < newKeysSize; j++){
                if(key[1][0] == newKeys[j][1][0]){ break; }
                if(j == newKeysSize - 1) {
                    newKeysSize += 1;
                    newKeys.resize(newKeysSize);
                    newKeys[newKeysSize-1] = key;
                }
            }
        }
    }
    return newKeys;
}

void ExecuteDirector::execute(std::vector<std::vector<std::vector<std::string>>> keys) {
    for(int i = 0; i < keys.size(); i++){
        for(int j = 0; j < EXECUTOR_OF_KEY.size(); j++){
            if(EXECUTOR_OF_KEY[j].isTriggerWord(keys[i][1][0])) {
                EXECUTOR_OF_KEY[j].execute(keys[i][3]);
                break;
            }
        }
    }
}
