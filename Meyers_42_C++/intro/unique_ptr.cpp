#include <iostream>
#include <memory>

int main() 
{
	std::unique_ptr<int> ptr1 = std::make_unique<int>(42);

	std::cout << " Value: " << *ptr1 << std::endl;

	std::unique_ptr<int> ptr2 = std::move(ptr1);

	if (!ptr1) {
		std::cout << "ptr1 null" << std::endl;
	}

	std::cout << "Value ptr2: " << *ptr2 << std::endl;

	return 0;
}

