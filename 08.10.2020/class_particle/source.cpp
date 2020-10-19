#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>

#include "particle.hpp"

int main()
{
	const double time = 10.28;

	Particle proton(0.0, 0.0, 0.0, 1, 1);
	Particle alpha(0.5, 0.5, 0.0, 4, 2);

	interaction(proton, alpha);
	proton.move(time);
	alpha.move(time);

	std::cout << proton << std::endl << alpha << std::endl;

	return 0;
}
