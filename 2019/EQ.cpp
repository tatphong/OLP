#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int n,p,k;
struct dd{
    int x,y,f;
}a[500010],b[5010];
void nhap()
{
    freopen("EQ.INP","r",stdin);
    cin>>n>>p>>k;
    for (int i=0;i<n;++i)
        cin>>a[i].x>>a[i].y;
    for (int i=0;i<p;++i)
        cin>>b[i].x>>b[i].y>>b[i].f;
}
bool vi_tri_anh_huong(dd b,dd a)
{
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2))<=pow(b.f,2);
}
bool cmp(dd a,dd b)
{
    return a.x<b.x || a.y<b.y || a.f<b.f;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    nhap();
    sort(a,a+n,cmp);
//    sort(b,b+p,cmp);
    for (int i=0;i<p;++i)
    {
        long long tam_ah=pow(b[i].f,2);
        for (int j=0;j<n;++j)
        {
            if (vi_tri_anh_huong(b[i],a[j])) a[j].f++;
            else
                if (a[j].x>b[i].x+tam_ah) break;
        }
    }
    int d=0;
    for (int i=0;i<n;++i)
        if (a[i].f>=k) ++d;
    freopen("EQ.OUT","w",stdout);
    cout<<d;
    return 0;
}

