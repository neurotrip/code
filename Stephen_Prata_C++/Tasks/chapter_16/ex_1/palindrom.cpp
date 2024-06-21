#include <iostream>
#include <string>
#include <algorithm>

// Функция для проверки строки на палиндром
bool isPalindrome(const std::string& str) {
    // Создаём копию строки
    std::string cleaned_str = str;

    // Удаляем пробелы из строки
    cleaned_str.erase(std::remove(cleaned_str.begin(), cleaned_str.end(), ' '), cleaned_str.end());

    // Приводим все символы к нижнему регистру
    std::transform(cleaned_str.begin(), cleaned_str.end(), cleaned_str.begin(), ::tolower);

    // Проверяем, является ли очищенная строка равной своему обратному отражению
    std::string reversed_str = cleaned_str;
    std::reverse(reversed_str.begin(), reversed_str.end());

    return cleaned_str == reversed_str;
}

int main() {
    std::string userInput;
    std::cout << "Введите строку: ";
    std::getline(std::cin, userInput);

    if (isPalindrome(userInput)) {
        std::cout << "Это палиндром!" << std::endl;
    } else {
        std::cout << "Это не палиндром." << std::endl;
    }

    return 0;
}

