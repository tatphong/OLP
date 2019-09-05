#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int a[256],b[256],n,m,s[256];
vector<pii>vt;
bool cmp(pii a,pii b)
{
    return a.first>b.first;
}
int main()
{
    cin>>n>>m;
    int x;
    int acolormax=0,bcolormax=0;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        a[x]++;
        acolormax=max(acolormax,x);
    }
    for (int i=0;i<m;++i)
    {
        cin>>x;
        b[x]++;
        bcolormax=max(bcolormax,x);
    }
    int scolormax=max(acolormax,bcolormax);
    for (int i=0;i<=scolormax;++i)
    {
        vt.push_back(pii(a[i]+b[i],i));
    }
    sort(vt.begin(),vt.end(),cmp);
    int demco=0,demmau=0;
    for (auto i:vt)
    {
        demco+=i.first;
        demmau++;
        if (demco>=n) {cout<<demmau;break;}
        //cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
