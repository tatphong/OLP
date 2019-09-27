#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
int n,a[1000010],sum[100010];
int a2[510][510],b2[250010];
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
int main()
{
//    bai1();
    bai2();
    return 0;
}
