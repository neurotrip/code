#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <valarray>
#include <string>

// Определение синонима типа для std::valarray<int>
typedef std::valarray<int> ArrayInt;

// Определение типа PairArray с помощью typedef
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
private:
    std::string label;
    int years;
    PairArray data;

public:
    Wine();
    Wine(const char *l, int y, const int yr[], const int bot[]);
    Wine(const char *l, int y);
    void GetBottle();
    void Show() const;
    const std::string &Label() const;
    int sum() const;
};

#endif // WINE_H_

