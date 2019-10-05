#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, a[10000][10000], mau = 0;
ii dem[10000];
string s[10000];
vector <int> bancolor[10000];
void nhap()
{
    freopen("TOMAU.INP", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
}
bool cmp(ii a, ii b)
{
    return a.second > b.second;
}
int tomau(int x)
{
    int m = 1;
    for (m = 1; m <= mau + 1; ++m)
    {
        bool color_banned=false;
        for (int i =0; i < bancolor[x].size(); ++i)
        {
            if (bancolor[x][i] == m)
                {color_banned=true;break;}
        }
        if (!color_banned)
            {mau = max(mau, m);return m;}
    }
}
void update_nutlienket(int x, int color)
{
    for (int i = 0; i < n; ++i)
        if (a[i][x] == 1)
        {
            --dem[i].second;
            bancolor[i].push_back(color);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    nhap();
    //count rank
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j])
            {
                dem[i].first = i;
                ++dem[i].second;
            }
        }
    //solve
    sort(dem, dem + n, cmp);
    while (n-- > 0)
    {
        int color = tomau(dem[0].first);
        update_nutlienket(dem[0].first, color);
        dem[0].second = 0;
        sort(dem, dem + n, cmp);
    }
    //result
    //    freopen("tomau.out","w",stdout);
    cout<<endl<< mau << endl;
    return 0;
}



//toi uu con sai******************************************
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, a[10000][10000], mau = 0, flagmax;
bool bancolor[10000][1000];
ii dem[10000];
string s[10000];
//vector <int> ;
void nhap()
{
    freopen("tomau.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
}
bool cmp(ii a, ii b)
{
    return a.second > b.second;
}
int tomau(int x)
{
    int m = 1;
    for (m = 1; m <= mau + 1; ++m)
    {
        cout<<x<<" "<<m<<" "<<bancolor[x][m]<<endl;
        if (bancolor[x][m]==0)
            {mau = max(mau, m);return m;}
    }
}
void update_nutlienket(int x, int color)
{
    int tempmax=flagmax;
    for (int i = 0; i < n; ++i)
        if (a[i][x] == 1)
        {
            --dem[i].second;
            bancolor[i][color]=1;
            if (dem[i].second>dem[tempmax].second) tempmax=i;
        }
    flagmax=tempmax;
    cout<<flagmax<<" "<<dem[flagmax].second<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    nhap();
    //count rank
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j]==1)
            {
                dem[i].first = i;
                ++dem[i].second;
            }
        }
//        cout<<i<<" "<<dem[i].second<<endl;
    }
    //solve
    sort(dem, dem + n, cmp);
//    for (int i=0;i<n;++i)
//        cout<<dem[i].first<<" "<<dem[i].second<<endl;
    flagmax=0;
    int k=n;
    while (k-- > 0 && dem[flagmax].second>0)
    {
        int color = tomau(dem[flagmax].first);
        dem[flagmax].second = 0;
        update_nutlienket(dem[flagmax].first, color);
//        sort(dem, dem + n, cmp);
    }
    //result
    //    freopen("tomau.out","w",stdout);
    cout<< mau;
    return 0;
}

