#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n,r,m,a[1000010];
ii st[4000010];
void update(int id,int l,int r,int i,int x)
{
    if (i<l||i>r) return ;
    if (l==r) {
        st[id].first=x;
        st[id].second=i;
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,i,x);
    update(id*2+1,m+1,r,i,x);
    st[id]=max(st[id*2],st[id*2+1]);
}
ii getmax(int id,int l,int r,int u,int v)
{
    if (v<l||r<u) return {-INFINITY,-INFINITY};
    if (l==r) return st[id];
    int m=(l+r)/2;
    return max(getmax(id*2,l,m,u,v),getmax(id*2+1,m+1,r,u,v));
}
ii getmin(int id,int l,int r,int u,int v)
{
    if (v<l||r<u) return {-INFINITY,-INFINITY};
    if (l==r) return st[id];
    int m=(l+r)/2;
    return min(getmin(id*2,l,m,u,v),getmin(id*2+1,m+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>r>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        update(1,1,n,i,a[i]);
    }
    int id=getmax(1,1,n,1,n).second;
    cout<<id<<" ";
//    cout<<id<<endl;
//    for (int j=id-r;j<=id+r;++j)
//        update(1,1,n,j,++a[j]);
//    for (int i=1;i<=n;++i)
//        cout<<getmax(1,1,n,i,i).first<<" ";
//        cout<<getmax(1,1,n,i,i).first<<" ";
    while (m--)
    {
        id=getmin(1,1,n,1,n).second;
        for (int j=id-r;j<=id+r;++j)
            update(1,1,n,j,++a[j]);
        id=getmax(1,1,n,1,n).second;
        for (int j=id-r;j<=id+r;++j)
        {
            update(1,1,n,j,0);
            a[j]=0;
        }
    }
    cout<<getmax(1,1,n,1,n).first;
    return 0;
}
