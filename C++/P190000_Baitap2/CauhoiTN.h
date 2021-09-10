#pragma once
#include <string>
#include <fstream>

using namespace std;

class CauhoiTN
{
private:
	string noidung;
	// Noi dung dap an A, B
	string dapanA;
	string dapanB;
	string caudung; //A hoac B
public:
	void nhap();
	void xuat();
	bool docfile(istream& f);
	void ghifile(ostream& f);
	void kiemtra();
	bool giongnhau(CauhoiTN, CauhoiTN);
	void xoakhoangcach();
};

