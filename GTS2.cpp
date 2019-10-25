#include<bits/stdc++.h>
using namespace std;
int n,a[1000][1000],cost_final=INT_MAX;
queue<int>tour_final;
void GTS1(int s)
{
    int i=s;
    int cost=0;
    map<int,bool>visited;
    queue<int>tour;
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
    if (cost<cost_final) {cost_final=cost;tour_final=tour;}
}
int main()
{
    freopen("GTS2.INP","r",stdin);
    cin>>n;
    for (int i=0;i<n;++i)
    for (int j=0;j<n;++j)
        cin>>a[i][j];

    //solve
    for (int i=0;i<n;++i)
        GTS1(i);

    //result
    cout<<cost_final<<endl;
    while(!tour_final.empty())
    {
        cout<<tour_final.front()+1<<" ";
        tour_final.pop();
    }
    return 0;
}
