#include "Point3D.h"
#include <math.h>;
#include <iostream>
using namespace std;

Point3D::Point3D()
{
	x = 0;
	y = 0;
	z = 0;
}
Point3D::Point3D(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point3D::Nhap()
{
	cout << "Nhap vao toa do diem" << endl;
	cout << "Nhap x: "; cin >> x;
	cout << "Nhap y: "; cin >> y;
	cout << "Nhap z: "; cin >> z;
}

void Point3D::Xuat()
{
	cout << "(" << x << ";" << y << ";" << z << ")" << endl;
}

bool Point3D::Kiemtratoadotrungnhau(Point3D p) 
{
	if (x == p.x && y == p.y && z == p.z)
		return true;
	return false;
}
double Point3D::Khoangcach(Point3D p)
{
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
}
