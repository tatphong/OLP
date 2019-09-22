#include<bits/stdc++.h>
using namespace std;
long long n;
vector <int> triex,l,r;
void doi_he_tam_phan()
{
    long long temp=n;
    while (temp>=3)
    {
        triex.push_back(temp%3);
        temp/=3;
    }
    triex.push_back(temp);
    triex.push_back(0);
}
int main()
{
    cin>>n;
    doi_he_tam_phan();
    /*for (auto i:triex)
        cout<<i;
    cout<<endl;*/
    for (int i=0;i<triex.size();++i)
    {
        //cout<<triex[i]<<" ";
        if (triex[i]==1)
        {
            r.push_back(i);
        }
        else if (triex[i]==2)
        {
            l.push_back(i);
            int j=i+1;
            if (triex[j]==2)
            {
                while (triex[j]==2)
                {
                    triex[j]=0;
                    ++j;
                }
                ++triex[j];
            }
            else ++triex[i+1];
        }
        else continue;
    }
    //cout<<endl;
    if (l.size()==0) cout<<-1;
    else for (auto i:l)
        cout<<i<<" ";
    cout<<endl;
    for (auto i:r)
        cout<<i<<" ";
    return 0;
}

