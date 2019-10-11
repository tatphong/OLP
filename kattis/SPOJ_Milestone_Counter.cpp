#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n,m,speed[1010],miles[1010];
map<long double,int>poss_speed;
map<ll,int>poss_dist;
int main()
{
    cin>>m>>n;
    for (int i=0;i<m;++i)
        cin>>speed[i];
    for (int i=0;i<n;++i)
        cin>>miles[i];

    //solve
    for (int i=0;i<=n-m;++i)
    {
        long double velocity=(miles[i+1]-miles[i])*1.0/(speed[1]-speed[0]);
        bool c=true;
        for (int j=0;j<m-1;++j)
        {
            if ((miles[i+j+1]-miles[i+j])*1.0/(speed[j+1]-speed[j])==velocity)
                continue;
            else c=false;
        }
        if (c)
        {
            poss_speed[velocity]=1;
            poss_dist[miles[i+1]-miles[i]]=1;
        }
    }
    cout<<poss_speed.size()<<endl;
    for (auto it=poss_dist.begin();it!=poss_dist.end();++it)
        cout<<it->first<<" ";
    return 0;
}
