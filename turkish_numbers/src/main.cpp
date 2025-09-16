#include <iostream>
#include "turkish_numbers.h"

int main()
{
    int number;

    // Чтение числа из стандартного ввода
    while (std::cin >> number)
    {
        try
        {
            std::string turkishName = numberToTurkish(number);
            std::cout << turkishName << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }

    return 0;
}