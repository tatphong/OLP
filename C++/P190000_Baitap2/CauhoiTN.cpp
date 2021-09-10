#include "CauhoiTN.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
void CauhoiTN::nhap()
{
	cin.ignore(0);
	cout << "Nhap noi dung cau hoi: ";
	getline(cin, noidung);
	cout << "Nhap cau tra loi A: ";
	getline(cin, dapanA);
	cout << "Nhap cau tra loi B: ";
	getline(cin, dapanB);
	cout << "Cau nao dung (A/B)? ";
	getline(cin, caudung);
}


void CauhoiTN::xuat()
{
	cout << noidung << endl;
	cout << "A. " << dapanA << endl;
	cout << "B. " << dapanB << endl;
}

bool CauhoiTN::docfile(istream& f)
{
	cin.ignore(0);
	getline(f, noidung);
	getline(f, dapanA);
	getline(f, dapanB);
	getline(f, caudung);
	if (noidung.length() > 0)
		return true;
	else
		return false;
}

void CauhoiTN::ghifile(ostream& f)
{
	f << noidung << endl;
	f << dapanA << endl;
	f << dapanB << endl;
	f << caudung << endl;
}

void CauhoiTN::kiemtra() 
{
	string dapan;
	this->xuat();
	cout << "Nhap dap an: "; cin >> dapan;
	if (dapan == caudung)
		cout << "Ban da tra loi dung." << endl;
	else
		cout << "Ban da tra loi sai." << endl;
}

bool CauhoiTN::giongnhau(CauhoiTN cau1, CauhoiTN cau2) 
{
	if (cau1.noidung == cau2.noidung)
		return true;
	return false;
}

void CauhoiTN::xoakhoangcach()
{
	int n = noidung.length();
	for (int i = 0; i < n-1; i++) 
	{
		if (noidung[i] == ' ' and noidung[i + 1] == ' ')
		{
			for (int j = i+1; j < n-1; j++)
				noidung[j] = noidung[j+1];
			noidung[n] = '\0';
			n--;
		}
	}
	this->xuat();
}