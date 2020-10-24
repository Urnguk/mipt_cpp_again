#include <iostream>

int main() {
	double a, b, c;

	std::cout << "please enter the coefficients a, b, c of the quadratic equation ";
	std::cout << "of the form: a*x^2 + b*x + c = 0 separated by a space.\n";

	std::cin >> a >> b >> c;

	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				std::cout << "there are an infinite number of roots\n";
			}
			else {
				std::cout << "there are no roots\n";
			}
		}
		else {
			std::cout << "the only root is x = " << (-c / b) << '\n';
		}
	}

	else {
		double D = std::pow(b, 2) - 4 * a * c;

		if (D == 0) {
			std::cout << "the only root is x = " << (-b / (2*a)) << '\n';
		}

		else {
			if (D < 0) {
				std::cout << "there are no roots\n";
			}

			else {
				std::cout << "the roots are x_1 = " << ((-b - std::pow(D, 0.5)) / (2 * a)) << " and x_2 = ";
				std::cout << ((-b + std::pow(D, 0.5)) / (2 * a)) << '\n';
			}
		}
	}

	system("pause");
	return 0;
}