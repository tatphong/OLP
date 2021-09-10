#include "Fraction.h"
#include <time.h>
#include <iostream>

using namespace std;

void Fraction::taophanso(int tu, int mau)
{
	this->tu = tu;
	this->mau = mau;
}

void Fraction::taophansongaunhien(int n) 
{
	tu = rand() % n;
	mau = rand() % n + 1;
}

void Fraction::xuat()
{
	cout << tu << "/" << mau << "\t";
}

bool Fraction::sosanh_bang(Fraction b) 
{
	double x = tu * 1.0 / mau;
	double y = b.tu * 1.0 / b.mau;;
	if (x == y)
		return true;

	return false;
}

bool Fraction::sosanh_lonhon(Fraction b)
{
	double x = tu * 1.0 / mau;
	double y = b.tu * 1.0 / b.mau;;
	if (x >= y)
		return true;

	return false;
}

void Fraction::dichbittrai(int n) 
{
	
}

void Fraction::dichbitphai(int n)
{

}