#include <iostream>
#include "Point3D.h";
#include <fstream>

using namespace std;
int main()
{
    cin.ignore(0);

    int n = 0;
    Point3D point[1000];

    //cau a
    ifstream fin = ifstream("Point3D.INP");
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        fin >> x >> y >> z;
        point[i] = Point3D(x, y, z);
    }
    
    fin.close();
    
    //cau b
    int kmax = 0;
    Point3D pmax1;
    Point3D pmax2;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
        {
            double kc = point[i].Khoangcach(point[j]);
            if (kc > kmax) {
                kmax = kc;
                pmax1 = point[i];
                pmax2 = point[j];
            }
        }
    cout << "Cap diem co khoang cach xa nhat: "; pmax1.Xuat(); cout << " va "; pmax2.Xuat(); cout << endl;

    //cau c
    Point3D ptrung[100];
    int m = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (point[i].Kiemtratoadotrungnhau(point[j])) {
                ptrung[m] = Point3D(point[i].x, point[i].y, point[i].z);
                m++;
            }
        }

    cout << "Toa do cac diem trung nhau: " << endl;
    if (m > 0)
        for (int i = 0; i < m; i++) {
            ptrung[i].Xuat();
        }
    else cout << "Khong co diem trung nhau.";

    //cau d
    ofstream fout = ofstream("Point3D.OUT");
    for (int i = 0; i < n; i++) {
        bool check = false;
        for (int j = 0; j < m; j++)
            if (point[i].Kiemtratoadotrungnhau(point[j]))
            {
                check = true;
                break;
            }
        if (!check)
            fout << point[i].x << " " << point[i].y << " " << point[i].z << endl;
    }
    fout.close();

    cout << endl;
}

