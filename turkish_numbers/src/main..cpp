#include <iostream>
#include <string>
#include <stdexcept>

std::string numberToTurkish(int number)
{
    if (number < 0 || number > 99)
    {
        throw std::out_of_range("Number must be between 0 and 99");
    }

    // Единицы
    const std::string units[] = {
        "sıfır", "bir", "iki", "üç", "dört",
        "beş", "altı", "yedi", "sekiz", "dokuz"};

    // Десятки
    const std::string tens[] = {
        "", "on", "yirmi", "otuz", "kırk",
        "elli", "altmış", "yetmiş", "seksen", "doksan"};

    // Особые случаи: 0 и числа, кратные 10
    if (number == 0)
    {
        return units[0];
    }
    if (number % 10 == 0)
    {
        return tens[number / 10];
    }

    // Составные числа
    int tensDigit = number / 10;
    int unitsDigit = number % 10;

    return tens[tensDigit] + " " + units[unitsDigit];
}

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