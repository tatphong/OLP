#include <bits/stdc++.h>

using namespace std;
string a[1001];
int n;
void nhap()
{
    //freopen("WLOOP.INP","r",stdin);
    cin>>n;
    cin.ignore();//xóa bộ nhớ đệm (sử dụng sau khi nhập số, dùng trước bị lỗi)
    for (int i=0;i<n;++i)
        getline(cin,a[i]);
}
int main()
{
    nhap();
    map <string,int> m;
    for (int i=0;i<n;++i)
    {
        m[a[i]]++;
    }
    int d=0;
    for (auto it=m.begin();it!=m.end();++it)
    {
        if (it->second > 1) d+=it->second-1;
    }
    cout<<d;
    return 0;
}
