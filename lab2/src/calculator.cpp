#include <iostream>
#include <string>
#include "calculator.h"

int Calculator::Add (int a, int b)
{
    return a + b;
}

int Calculator::Sub (int a, int b)
{
    return a - b;
}

int Calculator::Mul (int a, int b)
{
    return a * b;
}

int Calculator::Del (int a, int b)
{
    if(b != 0) {
        return a / b;
    } else {
        return 0.0;
    }
}

int Calculator::ReadFromConsole(std::string message) {
    std::string consoleLine;
    double number;

    std::cout << message << std::endl;

    while (true) {
        std::cin >> consoleLine;
        try {
            number = std::stoi(consoleLine);
        } catch (std::invalid_argument) {
            std::cout << "It's not integer." << std::endl;
            continue;
        }
        break;
    }
    return number;
}
