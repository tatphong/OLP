#include<bits/stdc++.h>
using namespace std;
int n,a[1000][1000],s,cost=0;
map<int,bool>visited;
queue<int>tour;
int main()
{
    freopen("GTS1.INP","r",stdin);
    cin>>n>>s;
    --s;
    for (int i=0;i<n;++i)
    for (int j=0;j<n;++j)
        cin>>a[i][j];

    //solve
    int i=s;
    while(visited[i]!=1)
    {
        tour.push(i);
        visited[i]=1;
        int wmin=INT_MAX, temp;
        for (int j=0;j<n;++j)
            if (visited[j]!=1 && wmin>a[i][j]) {wmin=a[i][j];temp=j;}
        i=temp;
        if (wmin!=INT_MAX)cost+=wmin;
        else cost+=a[i][s];
    }
    cout<<cost<<endl;
    while (!tour.empty())
    {
        cout<<tour.front()+1<<" ";
        tour.pop();
    }
    return 0;
}
