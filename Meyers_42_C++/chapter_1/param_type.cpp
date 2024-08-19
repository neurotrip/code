#include <iostream>

template <typename T>
void f_1(T& param)
{
	std::cout << "Param = " << param << std::endl;
}

template <typename K>
void f_2(K&& param)
{
	std::cout << "Param = " << param << std::endl;
}

template <typename A>
void f_3(A param) 
{
	std::cout << "Param = " << param + 1 << std::endl;
}

int main() 
{
	std::cout << "ParamType является указателем или ссылкой" << std::endl;
	int x = 27; 
	const int cx = x;
	const int& rx = x;
	f_1(x);
	f_1(cx);
	f_1(rx);
	std::cout << "ParamType является универсальной ссылкой" << std::endl;
	f_2(x);
	f_2(cx);
	f_2(rx);
	f_2(27);
	std::cout << "ParamType не является ни указателем, ни ссылкой" << std::endl; 
	f_3(x);
	f_3(cx);
	f_3(rx);

	return 0;
}


