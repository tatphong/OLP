#include<bits/stdc++.h> //AC 100
using namespace std;
typedef pair<int,int>ii;
typedef pair<char,int>ci;
int m,n,coast=0;
char a[1010][1010];
queue<ii>lake;
void loang(int i,int j)
{
    if (i+1<=m)
        if (a[i+1][j]=='0') {a[i+1][j]='2';loang(i+1,j);}
        else if (a[i+1][j]=='1') ++coast;
    if (i-1>=0)
        if (a[i-1][j]=='0') {a[i-1][j]='2';loang(i-1,j);}
        else if (a[i-1][j]=='1') ++coast;
    if (j+1<=n)
        if (a[i][j+1]=='0') {a[i][j+1]='2';loang(i,j+1);}
        else if (a[i][j+1]=='1') ++coast;
    if (j-1>=0)
        if (a[i][j-1]=='0') {a[i][j-1]='2';loang(i,j-1);}
        else if (a[i][j-1]=='1') ++coast;
}
int main()
{
    cin>>m>>n;
    ++m;++n;
    for (int i=0;i<=m;++i)
    for (int j=0;j<=n;++j)
        if (i==0||j==0||i==m||j==n)
            a[i][j]='0';
        else cin>>a[i][j];
    //solve
    a[0][0]='2';
    loang(0,0);
    cout<<coast;
    return 0;
}
