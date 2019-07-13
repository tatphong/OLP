/*
Cho một bảng vuông kích thước n x n (2<n<=100); trong đó mỗi phần tử của bảng là
một số nguyên không âm và có giá trị không vượt quá 100. Các dòng và cột của bảng
được đánh số bắt đầu từ 1. Ta gọi một bảng vuông con là bảng gồm các phần tử liền kề
nằm trong một hình vuông nào đó.
Yêu cầu:
Hãy tìm một bảng vuông con có tổng các phần tử là lớn nhất sao cho các phần tử của
nó chứa toàn số nguyên dương.
Dữ liệu vào được cho từ file TABLE.INP có cấu trúc như sau:
- Dòng đầu chứa số nguyên dương n;
- Trong n dòng tiếp theo mỗi dòng chứa n số nguyên không âm (tức chứa số 0 và
các số nguyên dương).
Dữ liệu kết quả được ghi ra file TABLE.OUT ghi một số nguyên duy nhất là tổng lớn
nhất tìm được.
Ví dụ:
TABLE.INP
5
12 9 0 7 6
6 5 2 3 0
1 7 2 5 18
0 2 2 3 7
2 12 13 0 4
TABLE.OUT
33 (bang : 5,18,3,7)
*/

#include <bits/stdc++.h>

using namespace std;
int n,a[101][101];
void create_rand_table(int x)
{
    freopen("TABLE.INP","w",stdout);
    cout<<x<<endl;
    for (int i=0;i<x;++i)
    for (int j=0;j<x;++j)
        cout<<rand()%100<<" ";
}
void nhap()
{
    freopen("TABLE.INP","r",stdin);
    cin>>n;
    for (int i=0;i<n;++i)
    for (int j=0;j<n;++j)
        cin>>a[i][j];
}
void timbangcon()
{
    int maxs=0;
    for (int k=2;k<=n;++k)
    for (int i=0;i<n-k+1;++i)
    for (int j=0;j<n-k+1;++j)
    {
        int s=0;
        for (int p=i;p<i+k;++p)
        for (int q=j;q<j+k;++q)
        {
            if (a[p][q]==0) {s=0;goto br;}
            s+=a[p][q];
        }
        //cout<<k<<" "<<i<<" "<<j<<" "<<s<<endl;
        br: if (s>maxs)maxs=s;
    }
    cout<<maxs;//dap an se xuat vao TABLE.INP lun :))
}
int main()
{
    create_rand_table(100);
    nhap();
    timbangcon();
    return 0;
}
