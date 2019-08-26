#include<bits/stdc++.h>
using namespace std;
typedef pair<long double,long double> dd;
int n,a[50],b[50];
dd d[50];
void timdodai()
{
    d[2].first=pow(2,-3*1.0/4);
    d[2].second=pow(2,-5*1.0/4);
    for (int i=3;i<=30;++i)
    {
        d[i].first=d[i-1].second;
        d[i].second=d[i-1].first/2;
    }
}
int main()
{
    cin>>n;
//    cout<<double(pow(2,-3*1.0/4))<<endl;
    int x;
    for (int i=2;i<=n;++i)
    {
        cin>>x;
        a[i]=x;
    }
    if (a[n]%2!=0) --a[n];
//    for (int i=n;i>1;--i)
//    {
//        b[i-1]=a[i-1]+a[i]/2+b[i]/2;
//        b[i]%=2;
//    }
//    for (int i=2;i<=n;++i)
//    {
//        a[i]-=b[i];
//        cout<<a[i]<<" ";
//    }
//    cout<<endl<<endl;
//    for (int i=1;i<=n;++i)
//        cout<<a[i]<<" "<<b[i]<<endl;
//    if (b[1]==0) {cout<<"impossible";return 0;}
    long long s=0,a1s=pow(2,29);
    for (int i=2;i<=n;++i)
    {
        s+=pow(2,30-i-1)*a[i];
        if (s>=a1s) ;
    }
    if (s<a1s) {cout<<"impossible";return 0;}
    timdodai();
    long double cv=0,a1=(d[2].first+d[2].second*2)*2;
    for (int i=2;i<=n;++i)
    {
//        cout<<d[i].first<<" "<<d[i].second<<endl;
        cv+=(d[i].first+d[i].second)*2*a[i];
    }
//    cout<<cv<<" "<<a1<<" ";
    cout<<setprecision(12)<<(cv-a1)/2;
    return 0;
}
