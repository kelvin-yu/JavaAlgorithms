#include<bits/stdc++.h>
using namespace std;

#define MAXN 50000
bool vis[MAXN];
vector<int> E[MAXN], revE[MAXN];
int id[MAXN];
stack<int> order;
int cnt = 0;
int N;

void dfs1(int i){
    vis[i] = true;
    for(auto j : E[i])
        if(!vis[j])
            dfs1(j);
    order.push(i);
}
void dfs2(int i){
    vis[i] = true;
    id[i] = cnt;
    for(auto j : revE[i])
        if(!vis[j])
            dfs2(j);
}

int main()
{
    for(int i = 0; i < N; i++){
        if(!vis[i])
            dfs1(i);
    }
    memset(vis, 0, sizeof vis);
    while(!order.empty()){
        int cur = order.top();
        order.pop();
        if(!vis[cur]){
            dfs2(cur);
            cnt++;
        }
    }
}
