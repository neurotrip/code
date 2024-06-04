#ifndef STONEWT1_H_
#define STONEWT1_H_
#include <iostream>
#include <ostream>
class Stonewt 
{
	private:
		enum {Lbs_per_stn = 14};
		int stone;
		double pds_left;
		double pounds;
	public:
		Stonewt(double lbs);
		Stonewt(int stn, double lbs);
		Stonewt();
		~Stonewt();
		friend std::ostream &operator <<(std::ostream & os, const Stonewt &t);
		Stonewt operator+(const Stonewt &s) const;
		Stonewt operator-(const Stonewt &s) const;
		operator int() const;
		operator double() const;
};

#endif 


