#include <string>

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    static int Add (int, int);
    static int Sub (int, int);
    static int Mul (int, int);
    static int Del (int, int);
    static int ReadFromConsole (std::string);
};

#endif//CALCULATOR_H