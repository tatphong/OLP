#include <iostream>
using namespace std;
typedef pair <int,int>ii;
int a[100010],cha[100010],st[10010];
void update(int id,int l,int r,int i,int x)
{
    if (i<l||i>r) return ;
    if (l==r)
    {
        st[id]=x;
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,i,x);
    update(id*2+1,m+1,r,i,x);
    st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
     if (v < l || r < u) return INT_MIN;
     if (u <= l && r <= v) return st[id];
     int m=(l+r)/2;
     return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
void bai2()
{
    int n,temp;
    cin>>n;
    temp=n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        update(1,1,n,i,a[i]);
    }
    for (int i=2;i<n;++i)
    {
        if (get(1,1,n,1,i-1)>a[i]&&a[i]<get(1,1,n,i+1,n))
        {
            a[i]=INT_MIN;
            --temp;
        }
    }
    cout<<temp<<endl;
    for (int i=1;i<=n;++i)
        if (a[i]!=INT_MIN) cout<<a[i]<<" ";
}
int tim_to_tien(int x,int con)
{
    if (cha[x]==con) return 0;
    if (cha[x]==0) return 1;
    return tim_to_tien(cha[x],con);
}

void bai3()
{
    for (int d=0;d<3;++d)
    {
        int n,m;
        ii a[100010];
        cin>>n>>m;
        for (int i=0;i<m;++i)
            cin>>a[i].first>>a[i].second;

        //reset data
        for (int i=0;i<=n;++i)
            cha[i]=0;

        //solve
        int check=1;
        for (int i=0;i<m;++i)
        {
            if (cha[a[i].second]==0) cha[a[i].second]=a[i].first;
            else {check=0;break;}
            if (tim_to_tien(a[i].first,a[i].second)==0)
            {
                check=0;
                break;
            }
        }
        cout<<check;
    }
}
void bai4()
{
    //co the dung binary_search de lam, do phuc tap O(n)
    int n,t;
    cin>>n>>t;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort (a,a+n);
    int brpoint=t-a[0];
    for (int i=0;i<t/2;++i)
    for (int j=t/2;j<n||a[j]>brpoint;++j)
        if (a[i]+a[j]==t) {cout<<a[i]<<" "<<a[j];i=n;j=n;}
}
int main()
{
    bai2();
//    bai3();
//    bai4();
    return 0;
}
