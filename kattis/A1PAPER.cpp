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
    int x;
    for (int i=2;i<=n;++i) //cin here
    {
        cin>>x;
        a[i]=x;
    }
//    if (a[n]%2!=0) --a[n];


    //solution
    long long s=0;
//    for (int i=2;i<=n;++i)
//    {
//        s+=pow(2,30-i-1)*a[i];
//        if (s>=a1s) ;
//    }
//    if (s<a1s) {cout<<"impossible";return 0;}

    //check
    int temp=2,check=0;
    for (int i=2;i<=n;++i)
    {
        if (temp>a[i])
        {
            temp-=a[i];
            temp*=2;
        }
        else
        {
            a[i]=temp;
            n=i;
            check=1;
        }
    }
//    for (int i=2;i<=n;++i)
//        cout<<a[i]<<" ";
    if (!check) {cout<<"impossible";return 0;}
    //solve
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
