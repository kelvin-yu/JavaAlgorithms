#include<bits/stdc++.h>
using namespace std;

#define MAXN 20001
int N, M, k;
vector<pair<int,int>> E[MAXN];
vector<int> dist[MAXN];
int main()
{
    priority_queue<pair<int,int>> q;
    q.push({0, 1});
    while(!q.empty()){
        int cost = -q.top().first;
        int cur = q.top().second;
        q.pop();
        if(dist[cur].size() == k)
            continue;
        if(dist[cur].size() == 0)
            dist[cur].push_back(cost);
        else if(dist[cur].back()!=cost)
            dist[cur].push_back(cost);
        else
            continue;
        for(auto e : E[cur]){
            if(dist[e.first].size() == k)
                continue;
            q.push({-(cost+e.second), e.first});
        }
    }
    if(dist[N].size() < k)
        cout << -1 << endl;
    else
        cout << dist[N][k-1] << endl;
}
