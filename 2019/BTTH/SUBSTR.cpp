#include<iostream>
#include<string>
using namespace std;
string a;
int p[260],l[260];
int main()
{
    cin>>a;
    p[0]=0;
    l[0]=1;
    for (int i=1;i<a.length();++i)
    {
        for (int j=i-1;j>=0;--j)
        {
            if (a[i]==a[j])
            {
                p[i]=j+1;
                l[i]=i-j;
                break;
            }
        }
        if (l[i]==0)
        {
            p[i]=p[i-1];
            l[i]=l[i-1]+1;
        }
    }
    int lmax=INT_MIN,pmax;
    for (int i=0;i<a.length();++i)
    {
        if (l[i]>lmax)
        {
            lmax=l[i];
            pmax=p[i]+1;
        }
    }
    cout<<pmax<<" "<<lmax;
    return 0;
}
