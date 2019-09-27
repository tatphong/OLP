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

