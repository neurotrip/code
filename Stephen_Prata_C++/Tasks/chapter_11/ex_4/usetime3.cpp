#include <iostream>
#include "mytime3.h"

int main()
{
	using std::cout;
	using std::endl;

	Time aida(3, 25);
	Time tosca(2, 48);
	Time temp;
	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida: " << aida << endl;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;



	temp = aida + 1;
	cout << "Aida + 1: " << temp << endl;
	cout << "10.0 + Tosca: " << tosca + 10 << endl;
	temp = aida - 1;
	cout << "Aida - 1: " << temp << endl;
	cout << "10.0 - Tosca: " << tosca - 1 << endl;

	return 0;
}

