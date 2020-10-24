#include <iostream>

int main() {
	const int len_const = 100;
	const int mass_const = 1000;
	const int time_const = 1;

	int flag;
	double x;

	std::cout << "please, choose and type the unit you'd like to convert.\n0 - length \n1 - mass \n";
	std::cout << "2 - time \n3 - force \n4 - energy \n";
	std::cin >> flag;

	switch (flag) {
		case 0:
			std::cout << "please enter the number in m, it will be given back in cm\n";
			std::cin >> x;
			std::cout << x * len_const << '\n';
			break;
		case 1:
			std::cout << "please enter the number in kg, it will be given back in g\n";
			std::cin >> x;
			std::cout << x * mass_const << '\n';
			break;
		case 2:
			std::cout << "please enter the number in s, it will be given back in s\n";
			std::cin >> x;
			std::cout << x * time_const << '\n';
			break;
		case 3:
			std::cout << "please enter the number in N, it will be given back in dyn\n";
			std::cin >> x;
			std::cout << x * len_const * mass_const / std::pow(time_const, 2) << '\n';
			break;
		case 4:
			std::cout << "please enter the number in J, it will be given back in erg\n";
			std::cin >> x;
			std::cout << x * std::pow(len_const, 2) * mass_const / std::pow(time_const, 2) << '\n';
			break;
		default:
			std::cout << "sorry but you've chosen the invalid option, try again please.\n";
	}

	system("pause");

	return 0;
}