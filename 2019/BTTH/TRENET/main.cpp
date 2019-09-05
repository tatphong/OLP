#include <bits/stdc++.h>
using namespace std;
int n,m;
struct netinfo
{
    int l,r,m;
};
netinfo a[10000];
void nhap()
{
    //freopen("TRENET.INP","r",stdin);
    cin>>n>>m;
}
void detect_info()
{
    a[1].l=1;
    a[1].r=1;
    a[1].m=1;
    for (int i=2;i<=100;++i)
    {
        a[i].l=a[i-1].r+1;
        a[i].r=a[i-1].r+(2*i-1);
        a[i].m=(a[i].l+a[i].r)/2;
    }
}
int floor(int n)
{
    for (int i=0;i<100;++i)
        if (a[i].l<=n&&a[i].r>=n) return i;
}
bool exch_floor(int nfloor,int n)
{
    if (n%2==nfloor%2) return true;
    return false;
}
void solve()
{
    int step=0;
    int nfloor=floor(n),mfloor=floor(m);
    if (nfloor>=mfloor)
    {
        while (n!=m)
        {
            if (nfloor==mfloor)
            {
                step+=abs(n-m);
                goto coo;
            }
            int dn=n-a[nfloor].m,dm=m-a[mfloor].m,mov=-1;
            ++step;
            if (!exch_floor(nfloor,n))
            {
                n-=a[nfloor].m-a[nfloor-1].m;
                --nfloor;
                continue;
            }
            if (dn<dm) mov=1; //mov=-1:left ; 1:right
            n+=mov;
        }
    }
    else
    {
        while (n!=m)
        {
            if (nfloor==mfloor)
            {
                step+=abs(n-m);
                goto coo;
            }
            int dn=n-a[nfloor].m,dm=m-a[mfloor].m,mov=-1;
            ++step;
            if (exch_floor(nfloor,n))
            {
                n+=a[nfloor+1].m-a[nfloor].m;
                ++nfloor;
                continue;
            }
            if (dn<dm) mov=1; //mov=-1:left ; 1:right
            n+=mov;
        }
    }
    coo: cout<<step;
}
int main()
{
    nhap();
    detect_info();
    solve();
    return 0;
}
