#include <iostream>
#include <vector>
#include <deque>
#include <string>

template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i) -> decltype(c[i]) {
	return c[i];
}

int main() {
	std::vector<int> vec = {1,2,3,4,5};
	auto& value1 = authAndAccess(vec, 2);
	std::cout << "Value from vector: " << value1 << std::endl;

	std::deque<std::string> deq = {"apple", "banana", "cherry"};
	auto& value2 = authAndAccess(deq, 1);
	std::cout << "Value from deque: " << value2 << std::endl;

	value2 = "blueberry";
	std::cout << "Modified deque: " << deq[1] << std::endl;

	return 0;
}

