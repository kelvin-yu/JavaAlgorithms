#include<bits/stdc++.h>
using namespace std;

#define MAXN 300000
#define INF 2e9
#define pb push_back
#define x first
#define y second

typedef pair<int,int> pii;
int N;
vector<pii> P;

struct Sort
{
    bool operator()(const pii& a, const pii& b) const
    {
        return (a.y < b.y);
    }
};

set<pii, Sort> S;

double dist(int x1, int x2, int y1, int y2){
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        P.pb({a, b});
    }
    sort(P.begin(), P.end());
    double d = INF;
    for(int i = 0; i < P.size(); i++){
        auto p = S.lower_bound({0, P[i].y - d});
        auto e = S.upper_bound({INF, P[i].y + d});
        while(p != e){
            d = min(d, dist(P[i].x, p->x, P[i].y, p->y));
            if(P[i].x - p->x > d){
                S.erase(p++);
            }
            else{
                p++;
            }
        }
        S.insert(P[i]);
    }
    printf("%.6f\n", d);
}
