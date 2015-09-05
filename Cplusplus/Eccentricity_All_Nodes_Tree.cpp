#include<bits/stdc++.h>
using namespace std;

#define MAXN 500001
vector<int> E[MAXN];
int ldist[MAXN], sdist[MAXN], lid[MAXN];
bool vis[MAXN];
int ans[MAXN];

void dfs1(int cur){
    vis[cur] = true;
    for(int v : E[cur]){
        if(!vis[v]){
            dfs1(v);
            if(ldist[v]+1 > ldist[cur]){
                sdist[cur] = ldist[cur];
                ldist[cur] = ldist[v]+1;
                lid[cur] = v;
            }
            else if(ldist[v]+1 > sdist[cur]){
                sdist[cur] = ldist[v]+1;
            }
        }
    }
}

void dfs2(int cur){
    vis[cur] = true;
    for(int v : E[cur]){
        if(!vis[v]){
            if(lid[cur] != v){
                ans[v] = max(ans[cur], ldist[cur]) + 1;
            }
            else{
                ans[v] = max(ans[cur], sdist[cur]) + 1;
            }
            dfs2(v);
        }
    }
    ans[cur] = max(ans[cur], ldist[cur]);
}

int main()
{

}
