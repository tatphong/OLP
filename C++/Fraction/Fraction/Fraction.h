#pragma once
#include <string>
class Fraction
{
public:
	int tu;
	int mau;

	void taophanso(int, int);
	void taophansongaunhien(int);
	void xuat();
	bool sosanh_bang(Fraction);
	bool sosanh_lonhon(Fraction);
	void dichbittrai(int);
	void dichbitphai(int);
};

