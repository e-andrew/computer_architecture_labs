#include <vector>
#include "string"

#ifndef AK_LAB_3_KEYEXECUTOR_H
#define AK_LAB_3_KEYEXECUTOR_H

class KeyExecutor {
private:
    std::string TRIGGER_WORD;
    std::string ACTION;
    bool IS_NEED_PARAMETER;
public:
    explicit KeyExecutor(std::string triggerWord, std::string action, bool isNeedParameter);
    bool isTriggerWord(std::string word);
    void execute(std::vector<std::string> parameters);
};

#endif
