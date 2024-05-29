#include <iostream>
#include <string>

struct CandyBar {
	const char * name;
	double weight;
	int calories;
};

void set_CandyBar(CandyBar &c_bar, const char *name = "Millennium Munch", double weight = 2.85, int calories = 350);
void show_CandyBar(CandyBar &c_bar);

int main()
{
	CandyBar bars[3];
	
	set_CandyBar(bars[0]);
	set_CandyBar(bars[1], "Tulskiy Pryanik", 3.11, 148);
	set_CandyBar(bars[2]);

	show_CandyBar(bars[0]);
	show_CandyBar(bars[1]);
	show_CandyBar(bars[2]);

	return 0;
}

void set_CandyBar(CandyBar &c_bar, const char *name, double weight, int calories)
{
	c_bar.name = name;
	c_bar.weight = weight;
	c_bar.calories = calories;
}

void show_CandyBar(CandyBar &c_bar)
{
	std::cout <<"Name: "<< c_bar.name << std::endl;
	std::cout <<"Weight: "<< c_bar.weight << std::endl;
	std::cout <<"Calories: "<< c_bar.calories << std::endl;
	std::cout << "\n";
}


