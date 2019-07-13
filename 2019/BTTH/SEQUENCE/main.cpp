/*
    Cho một dãy gồm n số nguyên a1,a2,...,an (n<=10^4). Hãy tìm giá trị lớn thứ k của dãy;
nếu dãy không tồn tại giá trị lớn thứ k của dãy thì tìm giá trị nhỏ nhất của dãy.
    Dữ liệu vào được cho từ file SEQUENCE.INP có cấu trúc như sau:
- Dòng đầu chứa 2 nguyên dương n,k.
- Trong các dòng tiếp theo chứa n số nguyên.
    Dữ liệu kết quả được ghi ra file SEQUENCE.OUT ghi một số nguyên duy nhất là kết
quả của bài toán.
Ví dụ 1:
SEQUENCE.INP
8 5
4 5 10 2 3 9 9 5
SEQUENCE.OUT
3

Ví dụ 2:
SEQUENCE.INP
8 6
5 4 5 7 7 2 7 4
SEQUENCE.OUT
2
*/
#include <bits/stdc++.h>

using namespace std;
int n,k,a[10010];
void nhap()
{
    //freopen("SEQUENCE.INP","r",stdin);
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
}
int main()
{
    nhap();
    sort(a,a+n);
    for (int j=n-2;j>=0;--j)
    {
        if (a[j]<a[j+1]) --k;
        if (k==1)
        {
            cout<<a[j];
            return 0;
        }
    }
    cout<<a[0];
    return 0;
}
