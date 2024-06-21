#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <valarray>

typedef std::valarray<int> ArrayInt;

template <typename T1, typename T2>
class Pair {
	private: 
		T1 years;
		T2 bottles;
	public:
		Pair(const T1 & yrs, const T2 & bts) :
			years(yrs), bottles(bts) {}
		 T1 & getYears() {return years;}
		 T2 & getBottles() {return bottles;}
		 const T1 & getYears() const {return years;}
		 const T2 & getBottles() const {return bottles;}
};

typedef Pair <ArrayInt, ArrayInt> PairArray;

class Wine
{
	private:
		std::string label;
		int years;
		PairArray data;
	public:
		Wine();
		Wine(const char *l, int y, const int yr[], const int bot[]);
		Wine(const char *l, int y);
		void GetBottle();
		std::string Label() const;
		int sum();
		void Show() const;
};

#endif 
		
