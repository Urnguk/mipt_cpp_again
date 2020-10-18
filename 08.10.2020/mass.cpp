#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>

class Mass
{

private:
	double m_in_kg;

public:
	Mass(double m) : m_in_kg(m) {}
	~Mass() {}

	static const double factor_to_g;
	static const double factor_to_Da;

	double get_in_kg() const
	{
		return m_in_kg;
	}

	double get_in_g() const
	{
		return m_in_kg * factor_to_g;
	}

	double get_in_Da() const
	{
		return m_in_kg * factor_to_Da;
	}
};

const double Mass::factor_to_g = 1000.0;
const double Mass::factor_to_Da = 1.66 * std::pow(10, -27);

int main()
{
	std::cout << "Please, enter the mass in kg:" << std::endl;

	double m = 0.0;
	std::cin >> m;

	Mass my_mass(m);
	std::cout << "The mass is equal to:" << std::endl
		<< "m = " << my_mass.get_in_kg() << " kg" << std::endl
		<< "m = " << my_mass.get_in_g() << " g" << std::endl
		<< "m = " << my_mass.get_in_Da() << " Da" << std::endl;

	return EXIT_SUCCESS;
}
