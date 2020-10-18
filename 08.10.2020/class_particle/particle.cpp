#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>

#include "particle.hpp"

inline double radius_vector(double x, double y, double z)
{
	return std::pow(x * x + y * y + z * z, 0.5);
}

Particle::Particle(double coord_1, double coord_2, double coord_3, int m, int ch,
	double vx, double vy, double vz, double ax, double ay, double az): 
	x(coord_1), y(coord_2), z(coord_3), mass(m), charge(ch), 
	v_x(vx), v_y(vy), v_z(vz), a_x(ax), a_y(ay), a_z(az) {}

double Particle::distance() const
{
	return radius_vector(x, y, z);
}

double Particle::velocity() const
{
	return radius_vector(v_x, v_y, v_z);
}

void Particle::move(double time_step)
{
	v_x += time_step * a_x;
	v_y += time_step * a_y;
	v_z += time_step * a_z;

	x += v_x * time_step;
	y += v_y * time_step;
	z += v_z * time_step;
}

void print(Particle& observed)
{
	std::cout << "The particle moved to the distance of: " << observed.distance() << std::endl
		<< "with the velocity of: " << observed.velocity() << std::endl;
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
