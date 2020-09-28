#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

inline double radius_vector(double x, double y, double z)
{
	return std::pow(x * x + y * y + z * z, 0.5);
}

struct Particle
{
	Particle(double coord_1, double coord_2, double coord_3, int m, int ch, double vx = 0.0, double vy = 0.0, double vz = 0.0, double ax = 0.0, double ay = 0.0, double az = 0.0) :
		x(coord_1), y(coord_2), z(coord_3), mass(m), charge(ch), v_x(vx), v_y(vy), v_z(vz), a_x(ax), a_y(ay), a_z(az) {}

	double x;
	double y;
	double z;

	double v_x;
	double v_y;
	double v_z;

	double a_x;
	double a_y;
	double a_z;

	int mass;
	short charge;

	double distance()
	{
		return radius_vector(x, y, z);
	}

	double velocity()
	{
		return radius_vector(v_x, v_y, v_z);
	}

	void move(double time_step)
	{
		v_x += time_step * a_x;
		v_y += time_step * a_y;
		v_z += time_step * a_z;

		x += v_x * time_step;
		y += v_y * time_step;
		z += v_z * time_step;
	}

	~Particle() {}


};

void print(Particle& observed)
{
	std::cout << "The particle moved to the distance of: " << observed.distance() << std::endl
		<< "with the velocity of: " << observed.velocity() << std::endl;
}

void interaction(Particle& A, Particle& B);

int main()
{
	const double time = 10.28;

	Particle proton(0.0, 0.0, 0.0, 1, 1);
	Particle alpha(0.5, 0.5, 0.0, 4, 2);

	interaction(proton, alpha);
	proton.move(time);
	alpha.move(time);

	print(proton);
	print(alpha);
	
	return 0;
}

void interaction(Particle& A, Particle& B)
{
	double d_x = B.x - A.x;
	double d_y = B.y - A.y;
	double d_z = B.z - A.z;

	double dist = radius_vector(d_x, d_y, d_z);

	double F = A.charge * B.charge / (std::pow(dist, 2));

	A.a_x += (F * d_x) / (dist * A.mass);
	A.a_y += (F * d_y) / (dist * A.mass);
	A.a_z += (F * d_z) / (dist * A.mass);

	B.a_x -= (F * d_x) / (dist * B.mass);
	B.a_y -= (F * d_y) / (dist * B.mass);
	B.a_z -= (F * d_z) / (dist * B.mass);
}
