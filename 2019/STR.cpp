#include <bits/stdc++.h>
//#include <iostream>
//#include <map>
using namespace std;
typedef pair <int,int>ii;
string a,b,c;
map <char,int> ma,mb;
void taofile()
{
    freopen("STR.INP","w",stdout);
    srand(time(nullptr));
    for (int i=0;i<10000;++i)
    {
        int r=rand()%26+97;
        cout<<char(r);
    }
    cout<<endl;
    for (int i=0;i<1000;++i)
    {
        int r=rand()%26+97;
        cout<<char(r);
    }
}
void nhap()
{
    freopen("STR.INP","r",stdin);
    cin>>a>>b;
    a="0"+a;
    b="0"+b;
}
int main()
{
    ios_base::sync_with_stdio(0);
//    taofile();
    nhap();

    int i=1,j=1,inear=0,jnear=0;
    while (i<b.length()||j<a.length())
    {
        if (mb[a[j]]&&inear<=mb[a[j]])
        {
            i=mb[a[j]];
//            cout<<a[j]<<" ";
            mb[a[j]]=0;
        }
        if (ma[b[i]]&&jnear<=ma[b[i]])
        {
            j=ma[b[i]];
//            cout<<b[i]<<" ";
            ma[b[i]]=0;
        }
        if (a[j]==b[i])
        {
            c+=a[j];
            inear=i;
            jnear=j;
            ++i;
            ++j;
            continue;
        }
        else
        {
            mb[b[i]]=i;
            ma[a[j]]=j;
//            cout<<a[j]<<" "<<b[i]<<endl;
            ++i;
            ++j;
        }
    }

//    freopen("STR.OUT","w",stdout);
    cout<<c;
    return 0;
}

