#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define pipi pair<ii,ii>
using namespace std;
ii a[8],point;
int n,np[4]={1,2,3,4};
bool b[4];
queue<pipi> emp;
void next(int k){
    if (k==4){
        for (int i=0;i<4;i++){
            cout<<np[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for (int i=1;i<=4;i++){
        if (b[i]==false){
            b[i]=true;
            np[k]=i;
            next(k+1);
            b[i]=false;
        }
    }
}

string solve(long long s)
{
    do
    {
        queue<pipi> q;
        queue<pipi> temp;
        q.push({{0,0},{0,0}});
        for (int i=0;i<4;i++)
        {
            temp=q;
            while(!q.empty())
                q.pop();
            while(!temp.empty())
            {
                point=temp.front().first;
                ii lr=temp.front().second;
//                cout<<point.first<<" "<<point.second<<" "<<lr.first<<" "<<lr.second<<" "<<np[i]<<endl;
                temp.pop();
                q.push({{point.first+a[np[i]].first,point.second},{point.first+a[np[i]].first,max(lr.second,a[np[i]].second)}});
                q.push({{point.first+a[np[i]].second,point.second},{point.first+a[np[i]].second,max(lr.second,a[np[i]].first)}});
                //relocate hcn
                q.push({{point.first,point.second+a[np[i]].first},{max(lr.first,a[np[i]].second),point.second+a[np[i]].first}});
                q.push({{point.first,point.second+a[np[i]].second},{max(lr.first,a[np[i]].first),point.second+a[np[i]].second}});
            }
        }
//        if (q.empty()) cout<<"TRUE"; else cout<<"FALSE";
        cout<<"***********************";
        while (!q.empty())
        {
            ii lr=q.front().second;
            point=q.front().first;
            cout<<point.first<<" "<<point.second<<" "<<lr.first<<" "<<lr.second<<" ";
            cout<<lr.first*lr.second<<endl;
            if (lr.first*lr.second==s)
            return "YES";
            q.pop();
        }
    } while (next_permutation(np,np+4));
    return "NO";
}
int main()
{
    cin>>n;
    while(n-->0)
    {
        long long s=0;
        for (int i=1;i<=4;++i)
        {
            cin>>a[i].first>>a[i].second;
            s+=a[i].first*a[i].second;
        }
        cout<<s<<"\n";
        cout<<solve(s);
    }

    //next(0);
    return 0;
}
