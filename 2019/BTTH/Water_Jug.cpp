#include<bits/stdc++.h>
#define pii pair<int, int>
#define iii pair<pii,int>
#define mp make_pair
using namespace std;
void BFS(int a, int b, int target)
{
    map<pii, int> m;
    bool isSolvable = false;
    queue<iii> q;
    q.push(iii(pii(0,0),0));
    q.push(iii(pii(a,0),1));
    q.push(iii(pii(0,b),1));
    while (!q.empty()) {
        iii u = q.front();
        q.pop();

        // if this state is already visited
        if (m[{ u.first.first, u.first.second }] == 1)
            continue;
        // doesn't met jug constraints
        if ((u.first.first > a || u.first.second > b || u.first.first < 0 || u.first.second < 0))
            continue;

        // marking current state as visited
        m[{ u.first.first, u.first.second }] = 1;

        // if we reach solution state, put ans=1
        if (u.first.first == target || u.first.second == target) {
            isSolvable = true;
            cout<<u.second;
            break;
        }
        q.push({{ u.first.first, b }, u.second+1}); // fill Jug2
        q.push({{ a, u.first.second }, u.second+1}); // fill Jug1
        q.push({{ max(u.first.first-(b-u.first.second), 0), min(b,u.first.first+u.first.second) }, u.second+1});//pour a to b
        q.push({{ min(a,u.first.first+b), max(u.first.first+b-a,0) }, u.second+1});//pour b to a
        q.push({{ u.first.first, 0 }, u.second+1}); // Empty Jug2
        q.push({{ 0, u.first.second }, u.second+1}); // Empty Jug1
    }

    // No, solution exists if ans=0
    if (!isSolvable)
        cout << -1;
}
int main()
{
    int Jug1, Jug2, target;
    cin>>Jug1>>Jug2>>target;
    BFS(max(Jug1,Jug2), min(Jug1,Jug2), target);
    return 0;
}
