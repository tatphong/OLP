#include <bits/stdc++.h>
using namespace std;
int n;
long long s=0,a[100001],b[100001];
void nhap()
{
    freopen("NUMPOLY.INP","r",stdin);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
}
void cach_phan_bo()
{
    sort(a,a+n);
    b[0]=a[0];
    for (int i=1;i<n*1.0/2;++i)
    {
        if (i%2==0)
        {
            b[i]=a[i-1];
            b[n-i]=a[i];
        }
        else
        {
            b[i]=a[n-i];
            b[n-i]=a[n-i-1];
        }
    }
    if (n%2==0) b[n/2]=a[n-n/2-1];
}
int main()
{
    nhap();
    cach_phan_bo();
    for (int i=0;i<n-2;++i)
    {
        for (int j=i+2;j<n;++j)
        {
            s+=b[i]*b[j]%1000000;
            //cout<<b[i]*b[j]<<" ";
            if (i==0 && j==n-2) break;
        }
    }
    cout<<s%100000;
    return 0;
}
