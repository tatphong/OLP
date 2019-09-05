#include <bits/stdc++.h>
using namespace std;
int n,k,a[1001],b[1001];
int smin=0,smax=0;
void nhap()
{
    //freopen("TICKET.INP","r",stdin);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>b[i];
}
int main()
{
    nhap();
    int tlen=0,txuong=0,uncheck=0;
    for (int i=1;i<=n;++i)
    {
        if ((i-1)%k==0)
        {
            txuong+=b[i];
            if (tlen>txuong)
            {
                smin+=uncheck-(tlen-txuong)<0?0:uncheck-(tlen-txuong);
                smax+=min(uncheck,txuong);
            }
            else
            {
                smin+=uncheck;
                smax+=uncheck;
            }
            //reset
            tlen=tlen-txuong+a[i];
            txuong=0;
            uncheck=0;
        }
        else
        {
            tlen+=a[i];
            txuong+=b[i];
            uncheck+=a[i];
        }
    }
    cout<<smin<<" "<<smax;
    return 0;
}
