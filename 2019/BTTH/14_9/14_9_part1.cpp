#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
int n,a[1000010];
void bai2()
{
    cin>>n;
    int ndayso=0,x,y,temp;
    for (int i=1;i<=n;++i)
    {
        ++ndayso;
        cin>>x>>y;
        for (int j=1;j<=ndayso;++j)
        {
            if (j==x)
            {
                for (int k=j;k<=ndayso;++k)
                {
                    temp=a[k];
                    a[k]=y;
                    y=temp;
                }
                j=ndayso;
            }
        }
    }
    for (int i=1;i<=ndayso;++i)
        cout<<a[i]<<" ";
}
void loang_center(int x,int y,ii a[3][3])
{
    int amax=0,xmax=x+1,ymax=y;
    if (a[x+1][y].second!=1 && x+1<3) amax=a[x+1][y].first;
    if (a[x-1][y].second!=1 && x-1>=0 && a[x-1][y].first>amax){amax=a[x-1][y].first;xmax=x-1;ymax=y;}
    if (a[x][y+1].second!=1 && y+1<3 && a[x][y+1].first>amax) {amax=a[x][y+1].first;xmax=x;ymax=y+1;}
    if (a[x][y-1].second!=1 && y-1>=0 && a[x][y-1].first>amax){amax=a[x][y-1].first;xmax=x;ymax=y-1;}
    a[xmax][ymax].second=1;
    if (amax!=0){cout<<amax;loang_center(xmax,ymax,a);}
}
void loang_corner(int x,int y,ii a[][3],int xbegin,int ybegin)
{
    int amax=0,xmax=x+1,ymax=y;
    if (x==1&&y==1)
    {
        if (a[xbegin+1][ybegin].second!=1 && xbegin+1<3) {amax=a[xbegin+1][ybegin].first;xmax=xbegin+1;ymax=ybegin;}
        if (a[xbegin-1][ybegin].second!=1 && xbegin-1>=0){amax=a[xbegin-1][ybegin].first;xmax=xbegin-1;ymax=ybegin;}
        if (a[xbegin][ybegin+1].second!=1 && ybegin+1<3) {amax=a[xbegin][ybegin+1].first;xmax=xbegin;ymax=ybegin+1;}
        if (a[xbegin][ybegin-1].second!=1 && ybegin-1>=0){amax=a[xbegin][ybegin-1].first;xmax=xbegin;ymax=ybegin-1;}
    }
    else
    {
        if (a[x+1][y].second!=1 && x+1<3) amax=a[x+1][y].first;
        if (a[x-1][y].second!=1 && x-1>=0 && a[x-1][y].first>amax){amax=a[x-1][y].first;xmax=x-1;ymax=y;}
        if (a[x][y+1].second!=1 && y+1<3 && a[x][y+1].first>amax) {amax=a[x][y+1].first;xmax=x;ymax=y+1;}
        if (a[x][y-1].second!=1 && y-1>=0 && a[x][y-1].first>amax){amax=a[x][y-1].first;xmax=x;ymax=y-1;}
    }
    a[xmax][ymax].second=1;
    if (amax!=0){cout<<amax;loang_corner(xmax,ymax,a,xbegin,ybegin);}
}
void bai3()
{
    cin>>n;
    int x,y;
    while (n--)
    {
        ii a[3][3];
        for (int i=0;i<3;++i)
        for (int j=0;j<3;++j)
        {
            cin>>a[i][j].first;
            if (a[i][j].first==9) {x=i;y=j;}
        }

        //solve 3 case
        if (x==1&&y==1)             //case: center
        {
            cout<<9;
            a[x][y].second=1;
            loang_center(x,y,a);
        }
        else if (x==1||y==1)        //case: half center
        {

        }
        else                        //case: corner
        {
            cout<<9;
            a[x][y].second=1;
            loang_corner(x,y,a,x,y);
        }
    }
}
void bai4()
{
    int m,p[100010],dem=0;
    ii ab[100010];
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>ab[i].first>>ab[i].second;
    for (int i=0;i<m;++i)
        cin>>p[i];
    sort(p,p+m);
    for (int i=0;i<n;++i)
    {
        if (ab[i].first>p[m-1]||ab[i].second<p[0])
            continue;
        else
        {
            int j1,j2;
            for (int j=0;j<m;++j)
                if (p[j]>=ab[i].first) {j1=j;break;}
            for (int j=m-1;j>=0;--j)
                if (p[j]<=ab[i].second){j2=j;break;}
            if (j2-j1+1>=2) dem++;
        }
    }
    cout<<dem;
}
int main()
{
//    bai2();
    bai3();
//    bai4();
    return 0;
}
