#include <iostream>
#include "Header.h"

using namespace std;


int main() {
	Vector3D vect(2, 4, 6);
	Vector3D vect1(1, 3, 5);

	vect *= 1.3;
	cout << vect << endl;

	cout << vect << "length: " << vect.len_vect() << endl << vect1 << "length: " << vect1.len_vect() << endl;

	cout << "vect == vect1 ? (1 - YES, 0 - NO)\nanswer: " << (vect == vect1) << endl;
	cout << "vect != vect1 ? (1 - YES, 0 - NO)\nanswer: " << (vect != vect1) << endl;

	vect1 = vect;

	cout << vect << "length: " << vect.len_vect() << endl << vect1 << "length: " << vect1.len_vect() << endl;

	cout << "vect == vect1 ? (1 - YES, 0 - NO)\nanswer: " << (vect == vect1) << endl;
	cout << "vect != vect1 ? (1 - YES, 0 - NO)\nanswer: " << (vect != vect1) << endl;
}