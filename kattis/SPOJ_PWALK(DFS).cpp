#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
vector <ii> g[100000]; // vector lưu các đỉnh kề với các đỉnh
int Visited[100000]; // mảng đánh dấu
int n,q;
void dfs(int u,int x,int res)
{
    if (u==x) cout<<res<<endl;
    Visited[u]=1;
    for (int i=0,v; i<g[u].size(); i++)
    {
        v=g[u][i].first;
        if (!Visited[v])
        {
            res+=g[u][i].second;
            dfs(v,x,res);
        }
    }
    res = 0;
}
int main()
{
    cin>>n>>q;
    int x,y,l;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y>>l;
        g[x].push_back({y,l});
        g[y].push_back({x,l});
    }
    int s,e;
    for (int i=0;i<q;++i)
    {
        cin>>s>>e;
        dfs(s,e,0);
        memset(Visited, 0, 100000);
    }
    return 0;
}
