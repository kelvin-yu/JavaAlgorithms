#include<bits/stdc++.h>
using namespace std;

#define LLINF                       LLONG_MAX
#define x                           first
#define y                           second
#define pb                          push_back

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;

int N;
vector<pll> P;
vector<pll> H;
int Hsize;

ll cross(pll O, pll A, pll B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

ll dot(pll O, pll A, pll B){
    return (A.x - O.x) * (B.x - O.x) + (A.y - O.y) * (B.y - O.y);
}

ld d(pll A, pll B){
    return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

vector<pll> convex_hull(vector<pll> P){
    int k = 0;
    vector<pll> H(2*P.size());
    sort(P.begin(), P.end());
    for(int i = 0; i < P.size(); i++){
        while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for(int i = P.size() - 2, t = k+1; i >= 0; i--){
        while(k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k-1);
    Hsize = k-1;
    return H;
}

ll ans = LLINF;
void rot_calipers(){
    int pointer = 1;
    int pointer2 = 1;
    int pointer3 = 1;
    for(int i = 0; i < Hsize; i++){
        //top
        while(cross(H[i], H[(i+1)%Hsize], H[pointer]) < cross(H[i], H[(i+1)%Hsize], H[(pointer+1)%Hsize])){
            pointer = (pointer+1)%Hsize;
        }
        //right
        while(dot(H[i], H[(i+1)%Hsize], H[pointer2]) < dot(H[i], H[(i+1)%Hsize], H[(pointer2+1)%Hsize])){
            pointer2 = (pointer2+1)%Hsize;
        }
        //left
        if(i == 0) pointer3 = pointer2;
        while(dot(H[i], H[(i+1)%Hsize], H[pointer3]) > dot(H[i], H[(i+1)%Hsize], H[(pointer3+1)%Hsize])){
            pointer3 = (pointer3+1)%Hsize;
        }
        ll height = abs(cross(H[i], H[(i+1)%Hsize], H[pointer]));
        ll left = abs(dot(H[i], H[(i+1)%Hsize], H[pointer3]));
        ll right = abs(dot(H[i], H[(i+1)%Hsize], H[pointer2]));
        ans = min(ans, (ll)(((ld)(left+right)/d(H[i],H[(i+1)%Hsize])*(ld)height/d(H[i],H[(i+1)%Hsize]))+0.5));
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        P.pb({a, b});
    }
    H = convex_hull(P);
    rot_calipers();
    cout << ans << endl;
}
