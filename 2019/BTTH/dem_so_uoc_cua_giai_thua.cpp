#include <bits/stdc++.h>
using namespace std;
int n,maxmu=0;
unsigned long long gt=1;
bitset<10000001>nt;
map<int,int>mp;
void sangnt()
{
    nt[0]=1;
    nt[1]=1;
    int nn=10000000;
    if (gt<10000000) nn=gt;
    for (int i=2;i<=sqrt(nn);++i)
    {
        if (nt[i]==0)
        for (int j=i+i;j<=nn;j+=i)
            nt[j]=1;
    }
}
void decrease_zero()
{
    while (gt%10==0)
    {
        gt/=10;
        ++mp[2];
        ++mp[5];
    }
}
int main()
{
    cin>>n;
    //find permutation
    for (int i=2;i<=n;++i)
        gt*=i;
    cout<<gt<<endl;

    sangnt();

    //solve
    decrease_zero();
    while (gt>1)
    {
        for (int i=2;i<=10000000;++i)
            if (nt[i]==0)
            while (gt%i==0)
            {
                gt/=i;
                ++mp[i];
                if (i>5 && nt[gt]==0) {++mp[gt];i=INT_MAX-1;gt=1;}
            }
    }

    //calc res
    long long res=1;
    for (auto it=mp.begin();it!=mp.end();++it)
        res*=(it->second+1);
    cout<<res-1;
    return 0;
}
