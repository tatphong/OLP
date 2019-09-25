#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n, a[10000][10000], mau = 0;
ii dem[10000];
string s[10000];
map<int, int> mp[10000];
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
        for (auto it = mp[x].begin(); it != mp[x].end(); ++it)
        {
            if (it->first == m && it->second == 1)
                continue;
        }
    mau = max(mau, m);
    return m;
}
void ktnutlienket(int x, int color)
{
    for (int i = 0; i < n; ++i)
        if (a[i][x] = 1)
        {
            --dem[i].second;
            mp[x][color] = 1;
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
    //
    //    cout<<n<<endl;
    //    for (int i=0;i<n;++i)
    //        cout<<s[i];
    //    for (int i=0;i<n;++i)
    //    {for (int j=0;j<n;++j)
    //        cout<<a[i][j];
    //        cout<<endl;
    //    }
    //    sort(dem,dem+n,cmp);
    //    for (int i=0;i<n;++i)
    //        cout<<dem[i].first<<" "<<dem[i].second<<endl;
    //    cout<<endl;
    //solve
    while (n-- > 0)
    {
        sort(dem, dem + n, cmp);
        int color = tomau(dem[0].first);
        ktnutlienket(dem[0].first, color);
        dem[0].second = 0;
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << "nut: " << i << endl;
        for (auto it = mp[i].begin(); it != mp[i].end(); ++it)
            cout << it->first << " " << it->second << endl;
    }
    //result
    //    freopen("tomau.out","w",stdout);
    cout << mau << endl;
    return 0;
}
