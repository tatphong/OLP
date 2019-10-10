#include<bits/stdc++.h>
using namespace std;
long long n,res;
bitset<1000010>nt;
map<int,int>mp;
void sangnt()
{
    nt[0]=1;
    nt[1]=1;
    int nn=1000000;
    if (n<1000000) nn=n;
    for (int i=2;i<=sqrt(nn);++i)
    {
        if (nt[i]==0)
        for (int j=i+i;j<=nn;j+=i)
            nt[j]=1;
    }
}
int main()
{
    cin>>n;
    sangnt();
    for (int i=2;i<=1000000||n!=1;++i)
        if (nt[i]==0)
            while (n%i==0)
            {
                n/=i;
                ++mp[i];
                if (i>5 && nt[n]==0) {++mp[n];i=INT_MAX-1;n=1;}
            }
    for (auto it=mp.begin();it!=mp.end();++it)
        res+=(it->second);
    cout<<res;
    return 0;
}
