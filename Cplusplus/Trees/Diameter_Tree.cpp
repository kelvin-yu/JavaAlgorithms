#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define mp make_pair

typedef pair<int,int> pii;

#define MAXN 40000
bool vis[MAXN];
vector<pii> E[MAXN];

pii diameter(int cur, bool root){
    vis[cur] = true;
    int maxi = 0,  i = cur;
    for(pii e : E[cur]){
        if(!vis[e.x]){
            pii v = diameter(e.x, false);
            if(v.x + e.y > maxi){
                maxi = v.x + e.y;
                i = v.y;
            }
        }
    }
    vis[cur] = false;
    if(root){
        return diameter(i, false);
    }
    return mp(maxi, i);
}

int main()
{

}
