#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
struct hcn
{
    ii left,right; //first:x ; second:y
};
int n;
hcn a[10000];
void nhap()
{
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a[i].left.first>>a[i].left.second>>a[i].right.first>>a[i].right.second;
    }
}
bool kt_a_con_b(hcn a,hcn b)
{
    if (a.left.first>=b.left.first&&a.left.second>=b.left.second&&a.right.first<=b.right.first&&a.right.second<=b.right.second)
        return true;
    return false;
}
int main()
{
    nhap();
    for (int i=0;i<n;++i)
    for (int j=0;j<n;++j)
    {
        if (kt_a_con_b(a[i],a[j]))
    }
    return 0;
}
