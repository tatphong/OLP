#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
int n,a[1000010],sum[100010];
int a2[510][510],b2[250010];
struct tower
{
    int d,r,w;
}a3[110];
int p3[110];
void bai1()
{
    int k,smax=INT_MIN;
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
    {
        if (i<k)
            sum[i]=sum[i-1]+a[i];
        else
        {
            sum[i]=sum[i-1]+a[i]-a[i-k];
            smax=max(smax,sum[i]);
        }
    }
    cout<<smax;
}
void bai2()
{
    int m,k;
    cin>>m>>n>>k;
    for (int i=1;i<=m;++i)
    for (int j=1;j<=n;++j)
        cin>>a2[i][j];

    //solve
    for (int i=1;i<=m;++i)
    for (int j=1;j<=n;++j)
    {
        b2[(i-1)*n+j]=a2[i-1][j]+a2[i][j-1]+a2[i-1][j-1]+a2[i+1][j]+a2[i][j+1]+a2[i+1][j+1]+a2[i-1][j+1]+a2[i+1][j-1];
    }
    sort(b2+1,b2+m*n+1);

    int x;
    for (int i=0;i<k;++i)
    {
        cin>>x;
        if (binary_search(b2+1,b2+m*n+1,x)) cout<<1<<" ";
        else cout<<0<<" ";
    }
}
bool cmp3(tower a,tower b)
{
    return a.r<b.r || a.d<b.d;
}
bool kt_a_thuoc_b(tower a,tower b)
{
    if (a.d<=b.d && a.r<=b.r) return true;
    return false;
}
void bai3()
{
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a3[i].d>>a3[i].r>>a3[i].w;
        if (a3[i].d<a3[i].r) swap(a3[i].d,a3[i].r);
    }

    //solve
    sort(a3,a3+n,cmp3);
    p3[0]=a3[0].w;
    for (int i=1;i<n;++i)  //quy hoach dong
    for (int j=i-1;j>=0;--j)
    {
        if (kt_a_thuoc_b(a3[j],a3[i])) p3[i]=max(p3[i],a3[i].w+p3[j]);
    }

    //result
    int res=0;
    for (int i=0;i<n;++i)
        res=max(res,p3[i]);
    cout<<res;
}
int main()
{
//    bai1();
//    bai2();
    bai3();
    return 0;
}
