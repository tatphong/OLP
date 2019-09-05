#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n,m,Q,maxw,newgraph,fa[500010],fa1[500010],check[500010],u[500010],v[500010],w[500010];
bool ans[500010];
vector <int> e[500010];
vector <ii> q[500010];
int get1(int x)
{
    if (fa[x]==x) return x;
    return fa[x]=get1(fa[x]);
}
int get2(int x)
{
    if (check[x]!=newgraph)
    {
        check[x]=newgraph;
        fa1[x]=fa[x];
    }
    if (fa1[x]==x) return x;
    return fa1[x]=get2(fa1[x]);
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        e[w[i]].push_back(i);
        maxw=max(maxw,w[i]);
    }
    cin>>Q;
    int x,k;
    for (int i=1;i<=Q;i++)
    {
        cin>>k;
        for (int j=1;j<=k;j++)
        {
            cin>>x;
            q[w[x]].push_back(make_pair(i,x));
        }
    }
    int id,idq,a,b;
    //khoi tao dsu
    for (int i=1;i<=n;i++)
    {
        fa[i]=i;
        fa1[i]=i;
    }
    for (int i=1;i<=maxw;i++)
    {
        sort(q[i].begin(),q[i].end());
        int lastidq=0;
        for (int j=0;j<q[i].size();j++)
        {
            id=q[i][j].second;
            idq=q[i][j].first;
            if (idq!=lastidq) newgraph++;
            a=get2(u[id]); b=get2(v[id]);
            if (a==b) ans[idq]=true;
            fa1[a]=fa1[b];
            lastidq=idq;
        }
        for (int j=0;j<e[i].size();j++)
        {
            id=e[i][j];
            a=get1(u[id]); b=get1(v[id]);
            if (a!=b)
                fa[a]=fa[b];
        }
    }
    for (int i=1;i<=Q;i++)
        if(ans[i]==false)
            printf("YES\n");
        else printf("NO\n");
}
