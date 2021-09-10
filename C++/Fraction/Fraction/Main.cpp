// Fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Fraction.h";
#include <iostream>

using namespace std;
int main()
{
    srand(time(NULL));
    int n;
    cout << "Nhap n: "; cin >> n;
    Fraction a[1000];
    Fraction x;
    x.taophanso(1, 2);

    //cau a
    for (int i = 0; i < n; i++)
    {
        a[i].taophansongaunhien(n);
        //cau b
        if (!a[i].sosanh_lonhon(x))
            a[i].xuat();
    }
    cout << endl;

    //cau c
    int b[1000] = { 0 };
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++)
            if (a[i].tu == a[j].tu && a[i].mau == a[j].mau)
            {
                b[i] = 1;
                b[j] = 1;
            }
    }

    for (int i = 0; i < n; i++)
        if (b[i] == 0)
            a[i].xuat();
    cout << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
