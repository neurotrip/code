#include "wine.h"

// Конструктор по умолчанию
Wine::Wine() : label(""), years(0), data(ArrayInt(), ArrayInt()) {}

// Конструктор с параметрами
Wine::Wine(const char *l, int y, const int yr[], const int bot[])
    : label(l), years(y), data(ArrayInt(yr, y), ArrayInt(bot, y)) {}

// Конструктор, принимающий только название и количество лет
Wine::Wine(const char *l, int y) : label(l), years(y), data(ArrayInt(y), ArrayInt(y)) {}

// Метод для ввода данных о бутылках
void Wine::GetBottle() {
    std::cout << "Enter " << years << " pairs of year and bottles:" << std::endl;
    for (int i = 0; i < years; ++i) {
        std::cout << "Year: ";
        std::cin >> data.getYears()[i];
        std::cout << "Bottles: ";
        std::cin >> data.getBottles()[i];
    }
}

// Метод для вывода данных
void Wine::Show() const {
    std::cout << "Wine: " << label << std::endl;
    std::cout << "      Year      Bottles\n";
    for (int i = 0; i < years; i++) {
        std::cout << "     " << data.getYears()[i]
                  << "     " << data.getBottles()[i] << std::endl;
    }
}

// Метод для получения метки
const std::string &Wine::Label() const {
    return label;
}

// Метод для суммирования количества бутылок
int Wine::sum() const {
    return data.getBottles().sum();
}

