#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>



int main()
{
	const double time = 10.28;
	
	struct molecule
	{
		molecule(double coord_1, double coord_2, double coord_3, int m, int ch):
			x(coord_1), y(coord_2), z(coord_3), mass(m), charge(ch)
		{
			v_x = 0;
			v_y = 0;
			v_z = 0;
		}
		
		double x;
		double y;
		double z;

		double v_x;
		double v_y;
		double v_z;
		
		int mass;
		short charge;

		double radius_vector()
		{
			return std::pow(x * x + y * y + z * z, 0.5);
		}

		double velocity()
		{
			return std::pow(v_x * v_x + v_y * v_y + v_z * v_z, 0.5);
		}

		void move(double time_step, double F_x, double F_y, double F_z)
		{
			v_x = time_step * F_x / mass;
			v_y = time_step * F_y / mass;
			v_z = time_step * F_z / mass;
			x += v_x * time_step;
			y += v_y * time_step;
			z += v_z * time_step;
		}

		~molecule()
		{
			std::cout << "the molecule was destroyed, while being at the disance of: " << radius_vector() << std::endl;
		}


	};

	molecule proton(0, 0, 0, 1, 1);
	molecule alpha(0.5, 0.5, 0, 4, 2);

	double delta_x = proton.x - alpha.x;
	double delta_y = proton.y - alpha.y;
	double delta_z = proton.z - alpha.z;

	double distance = std::pow(std::pow(delta_x, 2) +
		std::pow(delta_y, 2) + std::pow(delta_z, 2), 0.5);

	double Force = proton.charge * alpha.charge / (std::pow(delta_x, 2) +
		std::pow(delta_y, 2) + std::pow(delta_z, 2));

	double F_x = Force * delta_x / distance;
	double F_y = Force * delta_y / distance;
	double F_z = Force * delta_z / distance;

	proton.move(time, F_x, F_y, F_z);
	alpha.move(time, -F_x, -F_y, -F_z);

	std::cout << proton.velocity() << " " << alpha.velocity() << std::endl;
	return 0;
}
