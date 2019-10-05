#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[10001],maxchan=0,maxle=0;
bool kt_dx(int dau,int cuoi)
{
    while (s[dau]==s[cuoi]&&dau<cuoi)
    {
        ++dau;
        --cuoi;
    }
    if (dau<cuoi) return false;
    return true;
}
int main()
{
    cin>>s;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }

    //solve
    sort(a,a+n,greater<int>());
    while (1)
    {
        for (int i=0;i<s.length()-a[0];++i)
        {
            if (kt_dx(i,i+a[0]))
                if (a[0])
        }
    }
    return 0;
}
