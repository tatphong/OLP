#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],cv[1000];
int main()
{
    freopen("phancong.INP","r",stdin);
    cin>>n>>m;
    for (int i=0;i<m;++i)
        cin>>a[i];

    //solve
    sort(a,a+m,greater<int>());
    //note: cv[x] là tổng thời gian cần để máy x xong việc
    int i=0;
    while(i<m)
    {
        for (int j=0;j<n;++j)
            cv[j]+=a[i++];
        sort(cv,cv+n);
    }
    cout<<cv[n-1];
    return 0;
}
