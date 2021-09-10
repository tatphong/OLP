#include <iostream>
#include "CauhoiTN.h"
#include <fstream>

using namespace std;

int main()
{
    cout << "MSSSV-Ten  ----Bai tap 2----\n";

    int input;
    bool loop = true;
    while (loop) {
        cout << "1. Tao de thi trac nghiem." << endl;
        cout << "2. Xoa khoang trong thua o cac cau hoi." << endl;
        cout << "3. Lam kiem tra." << endl;
        cout << "4. Thoat chuong trinh." << endl;
        cout << "Chon chuc nang: "; cin >> input;
        switch (input) {
        case 1: {
            ofstream fout = ofstream("tracnghiem.TTN");
            string traloi;
            CauhoiTN cau1;

            do
            {
                cau1.nhap();
                cau1.ghifile(fout);
                cout << "Ban vua nhap mot cau hoi trac nghiem vao file." << endl;
                cout << "Co tiep tuc nhap khong (C/K)?";

                cin >> traloi;
            } while (traloi.find("C", 0) == 0);
            fout.close();
            break;
        }
        case 2: {
            CauhoiTN cau3[100];
            int fn = 0;
            ifstream fin = ifstream("tracnghiem.TTN");
            while (!fin.eof())
            {
                //cau3[fn] = new CauhoiTN();
                if (cau3[fn].docfile(fin))
                {
                    cau3[fn].xoakhoangcach();
                    fn++;
                }
            }
            
            fin.close();
            cout << fn << endl;
            ofstream fout = ofstream("tracnghiem.TTN");
            for (int ch = 0; ch < fn; ch++) {
                cau3[ch].ghifile(fout);
            }
            fout.close();
            break;
        }
        case 3: {
            ifstream fin = ifstream("tracnghiem.TTN");
            CauhoiTN cau2;
            while (!fin.eof())
            {
                if (cau2.docfile(fin))
                    cau2.kiemtra();
            }
            fin.close();
            break;
        }
        case 4: {
            loop = false;
            break;
        }
        default: {
            cout << "Vui long nhap lai lua chon phu hop!";
            break;
        }
        }
        cout << endl;
    }
}

