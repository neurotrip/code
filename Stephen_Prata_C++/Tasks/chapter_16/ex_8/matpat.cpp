#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Mat {
	std::string mat_friend;
};

struct Pat {
	std::string pat_friend;
};

int main() 
{
	std::vector<Mat> m_f;
	std::vector<Pat> p_f;
	
	Mat input;
	std::cout << "Insert Mat friend: \n";
	while (true) {
		std::cin >> input.mat_friend;
		if (input.mat_friend == "quit")
			break;
		m_f.push_back(input);
	}
	for (auto input : m_f) {
		std::cout << " " << input.mat_friend;
	}

	return 0;
}


		


