#pragma once
class Point3D
{
public:
	int x;
	int y;
	int z;
	Point3D();
	Point3D(int, int, int);
	void Nhap();
	void Xuat();
	bool Kiemtratoadotrungnhau(Point3D);
	double Khoangcach(Point3D);
};

