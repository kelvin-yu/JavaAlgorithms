#include<bits/stdc++.h>
using namespace std;

#define MAXN 300001

vector<pair<int,int>> G[MAXN];
int start;
int N, M;
int dist[MAXN];

int main()
{
    priority_queue<pair<int, int>> q;
    dist[start] = 0;
    q.push(make_pair(0, start));
    while(!q.empty()){
        int cost = -q.top().first;
        int cur = q.top().second;
        q.pop();
        if(dist[cur] < cost)
            continue;
        for(int i = 0; i < G[cur].size(); i++){
            int target = G[cur][i].first;
            int weight = G[cur][i].second;
            if(dist[target] > cost + weight){
                dist[target] = cost + weight;
                q.push(make_pair(-dist[target], target));
            }
        }
    }
}
