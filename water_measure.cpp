#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
int x,y,k,a,b;
int gcd(int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
bool is_measurability()
{
    return k%gcd(x,y)==0 && k<=max(x,y);
}
int main()
{
    cin>>x>>y>>k;//k là số lít nước cần đong
    //check if solvable
    if (!is_measurability()) {cout<<"Khong the dong duoc";return 0;}
    //solve
        //Áp dụng 3 luật sau:
//        (L1) Nếu bình X đầy thì đổ hết nước trong bình X đi.
//        (L2) Nếu bình Y rỗng thì đổ đầy nước vào bình Y.
//        (L3) Nếu bình X không đầy và bình Y không rỗng thì hãy trút nước t? bình Y sang bình X (cho đến khi bình X đầy hoặc bình Y hết nước).
    b=y;
    cout<<"Do day binh y "<<endl;
    while (a!=k && b!=k)
    {
        if (a!=x && b!=0)
        {
            int tempa=a;
            a=min(x,a+b);
            b=max(0,tempa+b-x);
            cout<<"Do nuoc tu y sang x "<<endl;
        }
        else if (b==0) {b=y;cout<<"Do day binh y "<<endl;}
        else if (a==x) {a=0;cout<<"Do het nuoc trong binh x "<<endl;}
    }
    return 0;
}
