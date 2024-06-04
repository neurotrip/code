#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "vect.h"
#include <fcntl.h>

int main()
{
	int fd = 0;
	int step_count = 0;
	int stdout_fd = dup(STDOUT_FILENO);
	fd = open("file.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1) {
		perror("Open file.txt");
		return 1;
	}
	if (stdout_fd == -1) {
		perror("stdout_fd");
		close(fd);
		return 1;
	}

	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	
	while (cin >> target) {
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		if (dup2(fd, STDOUT_FILENO) == -1) {
			perror("Duplicate diskr");
			close(fd);
			return 1;
		}

		cout << "Target Distance: "<< target << "Step Size: " << dstep;
		while (result.magval() < target) {
			cout << steps << ": (x, y)" << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		if (dup2(stdout_fd, STDOUT_FILENO) == -1) {
			perror("stdout_fd restart");
			close(fd);
			close(stdout_fd);
			return 1;
		}
		cout << "After " << steps << " steps, the subject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	close(stdout_fd);
	close(fd);
	cout  << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}

