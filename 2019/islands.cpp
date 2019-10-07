#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int>si;
int m,n;
si a[100][100];
void loang(int i,int j)
{
    if (a[i+1][j].first=="C"||a[i+1][j].first=="L") {a[i+1][j].second=1;loang(i+1,j);}
    if (a[i-1][j].first=="C"||a[i-1][j].first=="L") {a[i-1][j].second=1;loang(i-1,j);}
    if (a[i][j+1].first=="C"||a[i][j+1].first=="L") {a[i][j+1].second=1;loang(i,j+1);}
    if (a[i][j-1].first=="C"||a[i][j-1].first=="L") {a[i][j-1].second=1;loang(i,j-1);}
}
int main()
{
    while (cin>>m>>n)
    {
        for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            cin>>a[i][j].first;
        for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
        {
            if (a[i][j].first=="L")
            {
                a[i][j].second=1;
                loang(i,j);
            }
        }
    }
    return 0;
}
