#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//https://threads-iiith.quora.com/String-Hashing-for-competitive-programming
#define MAXN 100001
#define MOD 1000000007
#define BASE 43
ll prefixHash[MAXN];
ll pw[MAXN];
ll arr[MAXN];
int N;

ll rangeHash(int l, int r){
    return ((prefixHash[r] - prefixHash[l-1]) % MOD + MOD) % MOD;
}
//l2 >= l1
bool compHash(int l1, int r1, int l2, int r2){
    int h1 = rangeHash(l1, r1) * pw[l2-l1];
    int h2 = rangeHash(l2, r2);
    return (h1 == h2);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    pw[0] = 1;
    for(int j = 1; j <= N; j++){
        pw[j] = (pw[j-1] * BASE) % MOD;
        prefixHash[j] = (prefixHash[j-1] + (arr[j-1] * pw[j] % MOD)) % MOD;
    }
}
