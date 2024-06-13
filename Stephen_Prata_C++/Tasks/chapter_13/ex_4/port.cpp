#include <cstring>
#include <iostream>
#include "port.h"

// Class Port
Port::Port(const char *br, const char *st, int b)
{
	brand = new char [strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 20);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port & p) 
{
	brand = new char [strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	style[19] = '\0';
	bottles = p.bottles;
}

Port & Port::operator=(const Port &p)
{
	if (this == &p)
		return *this;
	delete [] brand;
	brand = new char [strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	style[19] = '\0';
	bottles = p.bottles;
	return *this;
}

Port & Port::operator+=(int b) 
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b) 
{
	bottles -= b;
	return *this;
}

void Port::Show() const 
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Style: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p)
{
	os << "Brand: " << p.brand << std::endl;
	os << "Style: " << p.style << std::endl;
	os << "Bottles: " << p.bottles << std::endl;
	return os;
}

//Class VintagePort 

VintagePort::VintagePort() 
: Port("none", "vintage", 0)
{
	nickname = new char [1];
	strcpy(nickname, "none");
	year = 0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) 
: Port(br, "vintage", b) 
{
	nickname = new char [strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort &vp) 
: Port(vp)
{
	nickname = new char [strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp) 
		return *this;
	Port::operator=(vp);
	delete [] nickname;
	nickname = new char [strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const 
{
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
	os << (const Port &) vp;
	os << "Nickname: " << vp.nickname << std::endl;
	os << "Year: " << vp.year << std::endl;
	return os;
}

	


