#include<bits/stdc++.h> //AC 100
using namespace std;
typedef pair<char,int>si;
int m,n,dem=0;
si a[100][100];
void loang(int i,int j)
{
    if (i+1<m && a[i+1][j].second==0 && (a[i+1][j].first=='C'||a[i+1][j].first=='L')) {a[i+1][j].second=1;loang(i+1,j);}
    if (i-1>=0 && a[i-1][j].second==0 && (a[i-1][j].first=='C'||a[i-1][j].first=='L')) {a[i-1][j].second=1;loang(i-1,j);}
    if (j+1<n && a[i][j+1].second==0 && (a[i][j+1].first=='C'||a[i][j+1].first=='L')) {a[i][j+1].second=1;loang(i,j+1);}
    if (j-1>=0 && a[i][j-1].second==0 && (a[i][j-1].first=='C'||a[i][j-1].first=='L')) {a[i][j-1].second=1;loang(i,j-1);}
}
int main()
{
    while (cin>>m>>n)
    {
        dem=0;
        for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            cin>>a[i][j].first;
        for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
        {
            if (a[i][j].first=='L' && a[i][j].second!=1)
            {
                a[i][j].second=1;
                loang(i,j);
                ++dem;
            }
        }
        cout<<dem;
    }
    return 0;
}

