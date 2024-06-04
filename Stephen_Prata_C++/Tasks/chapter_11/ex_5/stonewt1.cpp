#include <iostream>
using std::cout;
#include "stonewt1.h"

Stonewt::Stonewt(double lbs)
{
	stone = int (lbs) / Lbs_per_stn;
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() 
{
}

std::ostream &operator<<(std::ostream & os, const Stonewt & t)
{
	os << t.stone << " stone, " << t.pds_left << " left pounds\n";
	os << t.pounds << " pounds\n";
	return os;
}

Stonewt::operator int() const 
{
	return int  (pounds + 0.5);
}

Stonewt::operator double() const 
{
	return (pounds);
}

Stonewt Stonewt::operator+(const Stonewt &s) const 
{
	Stonewt sum;
	sum.pds_left = pds_left + s.pds_left;
	sum.pounds

