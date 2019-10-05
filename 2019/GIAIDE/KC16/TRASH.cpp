#include<bits/stdc++.h>
using namespace std;
int n,t,a[1000010],cach=0;
void tong_day_lien_tiep(int dodai)
{
    cach+=(1+dodai)*dodai/2;
}
int main()
{
    cin>>n>>t;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    //solve
    int dau,tong=0;
    for (int i=0;i<n;++i)
    {
        if (a[i]>t){tong=0;tong_day_lien_tiep(i-1-dau);continue;}
        if (a[i]==t){tong=0;++cach;tong_day_lien_tiep(i-1-dau);continue;}
        if (tong==0) dau=i;
        if (tong+a[i]<=t) {tong+=a[i];continue;}
        if (tong+)
    }
    return 0;
}
