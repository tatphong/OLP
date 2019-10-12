#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string a,b;
void nhap()
{
    freopen("GEN.INP","r",stdin);
    cin>>a>>b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    nhap();

    int len=0,maxlen=0,forlen=min(a.length(),b.length());
    for (int i=0;i<forlen;++i)
    {
        if (a[i]==b[i]) ++len;
        else
        {
            maxlen=max(len,maxlen);
            len=0;
            if (maxlen>=forlen-i) break;
        }
    }

    freopen("GEN.OUT","w",stdout);
    cout<<maxlen;
    return 0;
}
