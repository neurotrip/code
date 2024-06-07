#include <cstring>
#include <ostream>
#include <cctype>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::How(char ch)
{
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ch) 
			count++;
	}
	return count;
}

void String::to_lower()
{
	for (int i = 0; i < len; i++) {
		str[i] = std::tolower(str[i]);
	}
}
void String::to_upper()
{
	for (int i = 0; i < len; i++) {
		str[i] = std::toupper(str[i]);
	}
}
int String::HowMany()
{
	return num_strings;
}

String::String(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String &st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete [] str;
}

String & String::operator=(const String &st)
{
	if (this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String & String::operator=(const char *s)
{
	delete []str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const 
{
	return str[i];
}

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return st2.str < st1.str;
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

String  operator+(const String &st1, const String &st2)
{
	int _len = strlen(st1.str) + strlen(st2.str);
	char *sum = new char[_len + 1];
	std::strcpy(sum, st1.str);
	std::strcat(sum, st2.str);
	String result(sum);
	delete [] sum;
	return result;
}
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
