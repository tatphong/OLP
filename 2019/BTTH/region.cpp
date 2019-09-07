#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef pair <int,int> ii;
int n,m,k,a[10000][10000];
queue <ii> qu;
void loang(int i,int j)
{
    if (a[i][j+1]==0 && j+1<=n) {a[i][j+1]=1;qu.push(ii(i,j+1));};
    if (a[i+1][j]==0 && i+1<=m) {a[i+1][j]=1;qu.push(ii(i+1,j));};
    if (a[i][j-1]==0 && j-1>0) {a[i][j-1]=1;qu.push(ii(i,j-1));};
    if (a[i-1][j]==0 && i-1>0) {a[i-1][j]=1;qu.push(ii(i-1,j));};
}
int main()
{
    cin>>m>>n>>k;
    int x,y,z,t;
    for (int i=0;i<k;++i)
    {
        cin>>x>>y>>z>>t;
        for (int p=x;p<=z;++p)
        for (int q=y;q<=t;++q)
            a[p][q]=1;
    }
    int dem=0;
    for (int i=1;i<=m;++i)
    for (int j=1;j<=n;++j)
    {
        if (a[i][j]==0)
        {
            dem++;
            a[i][j]=1;
            qu.push(ii(i,j));
            while (!qu.empty())
            {
                ii temp=qu.front();
                qu.pop();
                loang(temp.first,temp.second);
            }
        }
    }

    cout<<dem;
    return 0;
}
