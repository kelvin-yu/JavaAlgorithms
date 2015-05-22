#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
bool sieve[MAXN];
int main()
{
    memset(sieve, 1, sizeof sieve);
    sieve[0] = 0;
    sieve[1] = 0;
    int root = sqrt(MAXN);
    for(int i = 2; i < root; i++){
        if(sieve[i]){
            for(int x = i*2; x < MAXN; x+=i){
                sieve[x] = 0;
            }
        }
    }
}
