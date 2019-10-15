#include <bits/stdc++.h>
using namespace std;
string a,b;
void taofile()
{
    freopen("GEN.INP","w",stdout);
    srand(time(nullptr));
    for (int i=0;i<1000000;++i)
    {
        int r=rand()%4;
        switch (r)
        {
            case 0:
                {cout<<'T';
                break;}
            case 1:
                {cout<<'X';
                break;}
            case 2:
                {cout<<'A';
                break;}
            default :
                {cout<<'G';
                break;}
        }
    }
    cout<<endl;
    for (int i=0;i<1000000;++i)
    {
        int r=rand()%4;
        switch (r)
        {
            case 0:
                {cout<<'T';
                break;}
            case 1:
                {cout<<'X';
                break;}
            case 2:
                {cout<<'A';
                break;}
            default :
                {cout<<'G';
                break;}
        }
    }
}
void nhap()
{
    freopen("GEN.INP","r",stdin);
    cin>>a>>b;
    cout<<a.length()<<" "<<b.length()<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    taofile();
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
