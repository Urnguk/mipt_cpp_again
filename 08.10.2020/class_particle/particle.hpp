#pragma once

class Particle
{
public:
	Particle(double coord_1, double coord_2, double coord_3, int m, int ch,
		double vx = 0.0, double vy = 0.0, double vz = 0.0, double ax = 0.0, double ay = 0.0, double az = 0.0);
	~Particle() = default;

	double distance() const;
	double velocity() const;

	void move(double time_step);
	friend void interaction(Particle& A, Particle& B);

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
	short charge;
};

void print(Particle& observed);
