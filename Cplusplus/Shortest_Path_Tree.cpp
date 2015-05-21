#include<bits/stdc++.h>
using namespace std;

#define MAXN 300001

vector<pair<int,int>> G[MAXN];
int start;
int N, M;
int dist[MAXN], weights[MAXN];
int edgeUsed[MAXN];

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
            int edgeIndex = G[cur][i].second;
            int weight = weights[edgeIndex];
            if(dist[target] > cost + weight){
                dist[target] = cost + weight;
                edgeUsed[target] = edgeIndex;
                q.push(make_pair(-dist[target], target));
            }
            else if(dist[target] == cost + weight){
                edgeUsed[target] = edgeIndex;
            }
        }
    }
    int sum = 0;
        for(int i = 0; i < N; i++){
        if(i != start){
            sum+=weights[edgeUsed[i]];
        }
    }
    cout << sum << endl;
    for(int i = 0; i < N; i++){
        if(i != start){
            cout << edgeUsed[i] + 1 << " ";
        }
    }
}
