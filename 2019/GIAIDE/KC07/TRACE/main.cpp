#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
};
point s,e;
string a;
void nhap()
{
    //freopen("TRACE.INP","r",stdin);
    cin>>s.x>>s.y>>e.x>>e.y;
    cin>>a;
}
int main()
{
    nhap();
    int unspos=0;
    for (int i=0;i<a.length();++i)
    {
        switch (a[i])
        {
            case 'E':
                ++s.x;
                break;
            case 'W':
                --s.x;
                break;
            case 'N':
                ++s.y;
                break;
            case 'S':
                --s.y;
                break;
            default:
                unspos++;
                break;
        }
    }
    int time=0,dist=abs(e.y-s.y)+abs(e.x-s.x);
    if (dist>unspos) time=dist-unspos;
    for (int i=0;i<a.length();++i)
    {
        int despos=0;
        if (a[i]!='E'&&a[i]!='W'&&a[i]!='S'&&a[i]!='N')
        {
            if (despos<time) {a[i]='E';++despos;}
            if ()
        }
    }
    return 0;
}
