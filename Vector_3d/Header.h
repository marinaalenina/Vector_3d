#include <iostream>
#include <math.h>
#include <string>


const double EPSILON = 0.001;


class Vector3D {
private:
	union {
		struct {
			double x, y, z;
		};
		double vect[3];
	};
	void normalize();

public:
	Vector3D() : x(0), y(0), z(0) {}

	Vector3D(const Vector3D& v) : x(v.x), y(v.y), z(v.z) {}

	Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

	Vector3D& operator=(const Vector3D& v);
	Vector3D& operator=(Vector3D&& v);

	bool operator==(const Vector3D& v) const;
	bool operator!=(const Vector3D& v) const;

	Vector3D operator-() const;

	friend Vector3D operator+(const Vector3D& v, Vector3D& v1);
	friend Vector3D operator-(const Vector3D& v, Vector3D& v1);
	friend Vector3D operator*(const Vector3D& v, const double& a);
	friend Vector3D operator/(const Vector3D& v, const double& a);
	
	double operator*(const Vector3D& v);

	double len_vect();

	Vector3D multiply_vect(Vector3D& v);

	friend Vector3D operator+=(Vector3D& v, const Vector3D& v1);
	friend Vector3D operator-=(Vector3D& v, const Vector3D& v1);
	friend Vector3D operator*=(Vector3D& v, const double& a);
	friend Vector3D operator/=(Vector3D& v, const double& a);

	friend std::ostream& operator<<(std::ostream& stream, const Vector3D& vect);
};