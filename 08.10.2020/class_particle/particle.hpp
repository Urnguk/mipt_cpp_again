#pragma once

inline double radius_vector(double x, double y, double z)
{
	return std::pow(x * x + y * y + z * z, 0.5);
}

class Particle
{
public:
	Particle(double coord_1, double coord_2, double coord_3, int m, int ch,
		double vx = 0.0, double vy = 0.0, double vz = 0.0, double ax = 0.0, double ay = 0.0, double az = 0.0);
	~Particle() = default;

	double distance() const { return radius_vector(x, y, z); }
	double velocity() const { return radius_vector(v_x, v_y, v_z); }

	void move(double time_step);
	friend void interaction(Particle& A, Particle& B);

	friend std::ostream& operator<< (std::ostream& out, const Particle observed);

private:

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
	int charge;
};
