#include <iostream>
#include <functional>
#include <memory>

auto  derefLess = [](const std::unique_ptr<int>& p1, const std::unique_ptr<int>& p2) {
	return *p1 < *p2;
};

int main() 
{
	std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
	std::unique_ptr<int> ptr2 = std::make_unique<int>(20);

	if (derefLess(ptr1, ptr2)) {
		std::cout << "ptr1 points to a smaller value than ptr2" << std::endl;
	} else {
		std::cout << "[tr1 points to a lager or equal value than ptr2" << std::endl;
	}

	return 0;
}

