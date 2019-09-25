#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
int n,m,p[100010],dem=0;
ii ab[100010];
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>ab[i].first>>ab[i].second;
    for (int i=0;i<m;++i)
        cin>>p[i];
    sort(p,p+m);
    for (int i=0;i<n;++i)
    {
        if (ab[i].first>p[m-1]||ab[i].second<p[0])
            continue;
        else
        {
            int j1,j2;
            for (int j=0;j<m;++j)
                if (p[j]>=ab[i].first) {j1=j;break;}
            for (int j=m-1;j>=0;--j)
                if (p[j]<=ab[i].second){j2=j;break;}
            if (j2-j1+1>=2) dem++;
        }
    }
    cout<<dem;
    return 0;
}
