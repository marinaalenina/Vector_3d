#include <iostream>
#include <math.h>
#include "Header.h"

	// ������������ �������
	void Vector3D::normalize() {
		double inverted_len = 1 / len_vect();
		if (len_vect() > 0) {
			x *= inverted_len;
			y *= inverted_len;
			z *= inverted_len;
		}
	}

	// ������������� ��������
	Vector3D& Vector3D::operator=(const Vector3D& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	Vector3D& Vector3D::operator=(Vector3D&& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	// ��������� ��������
	bool Vector3D::operator==(const Vector3D& v) const{
		if (fabs(x - v.x) < EPSILON)
			if (fabs(y - v.y) < EPSILON)
				if (fabs(z - v.z) < EPSILON)
					return true;
		return false;
	}

	bool Vector3D::operator!=(const Vector3D& v) const {
		if (fabs(x - v.x) < EPSILON)
			if (fabs(y - v.y) < EPSILON)
				if (fabs(z - v.z) < EPSILON)
					return false;
		return true;
	}

	// ������������� ������ (������� ��������!!!)
	Vector3D Vector3D::operator-() const {
		return Vector3D(-x, -y, -z);
	}

	// �������� ��������
	Vector3D operator+(const Vector3D& v, Vector3D& v1) {
		return Vector3D(v1.x + v.x, v1.y + v.y, v1.z + v.z);
	}

	// �������� ��������
	Vector3D operator-(const Vector3D& v, Vector3D& v1) {
		return Vector3D(v.x - v1.x, v.y - v1.y, v.z - v1.z);
	}

	// ��������� ������� �� ������
	Vector3D operator*(const Vector3D& v, const double& a) {
		return Vector3D(v.x * a, v.y * a, v.z * a);
	}

	// ������� ������� �� ������
	Vector3D operator/(const Vector3D& v, const double& a) {
		float b = 1.0f / a;
		return Vector3D(v.x * b, v.y * b, v.z * b);
	}

	// ��������� ����������� ��������
	double Vector3D::operator*(const Vector3D& v) {
		return x * v.x + y * v.y + z * v.z;
	}

	// �������� �������
	double Vector3D::len_vect() {
		return sqrt(x * x + y * y + z * z);
	}

	// ��������� ������������ ��������
	Vector3D Vector3D::multiply_vect(Vector3D& v) {
		return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	// ���������� �������� +, -, *, /
	Vector3D operator+=(Vector3D& v, const Vector3D& v1) {
		return Vector3D(v.x = v.x + v1.x, v.y = v.y + v1.y, v.z = v.z + v1.z);
	}

	Vector3D operator-=(Vector3D& v, const Vector3D& v1) {
		return Vector3D(v.x = v.x - v1.x, v.y = v.y - v1.y, v.z = v.z - v1.z);
	}

	Vector3D operator*=(Vector3D& v, const double& a) {
		return Vector3D(v.x = v.x * a, v.y = v.y * a, v.z = v.z * a);
	}

	Vector3D operator/=(Vector3D& v, const double& a) {
		float b = 1.0f / a;
		return Vector3D(v.x = v.x * b, v.y = v.y * b, v.z = v.z * b);
	}

	// ����� �������
	std::ostream& operator<<(std::ostream& stream, const Vector3D& vect) {
		stream << "Vector:\nx = " << vect.x << "\ny = " << vect.y << "\nz = " << vect.z << "\n";
		return stream;
	}