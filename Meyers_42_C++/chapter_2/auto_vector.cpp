#include <iostream>
#include <vector>

template<typename It>
void printElements(It begin , It end) {
	while (begin != end) {
		auto value = *begin;
		std::cout << value << " ";
		++begin;
	}
	std::cout << std::endl;
}

int main() 
{
	std::vector<int> vec = {1,2,3,4,5};
	printElements(vec.begin(), vec.end());
	return 0;
}

