#include <iostream>
#include "calculator.h"

int main() {
    int op, a, b, res;
    std::string StopWord;
    a = Calculator::ReadFromConsole("Input value a:");
    b = Calculator::ReadFromConsole("Input value b:");
    while(true)
    {
        op = Calculator::ReadFromConsole("Choose operation: 1 - add; 2 - sub; 3 - mul; 4 - del");
        if(op == 1){res = Calculator::Add(a, b); break;}
        else if(op == 2)
        {
            res = Calculator::Sub(a, b);
            break;
        } else if(op == 3)
        {
            res = Calculator::Mul(a, b);
            break;
        } else if(op == 4)
        {
            res = Calculator::Del(a, b);
            break;
        } else{ continue;}
    }
    std::cout << "Result: " << res << std::endl;
    std::cout << "Input \"stop\" to end program execution:" << std::endl;
    while(true) {
        StopWord = "";
        std::cin >> StopWord;
        if(StopWord == "stop") {
            break;
        }
    }
    return 0;
}
