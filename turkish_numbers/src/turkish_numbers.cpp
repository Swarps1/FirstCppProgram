#include "turkish_numbers.h"

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

    int tensDigit = number / 10;
    int unitsDigit = number % 10;

    if (tensDigit == 0)
    {
        return units[unitsDigit]; // Только единицы без пробела
    }
    else
    {
        return tens[tensDigit] + " " + units[unitsDigit]; // Десятки + пробел + единицы
    }
}