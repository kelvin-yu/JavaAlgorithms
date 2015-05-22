#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
bool sieve[MAXN];
int greatestPFactor[MAXN];
int numOfFactors[MAXN];
int main()
{
    memset(sieve, 1, sizeof sieve);
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i = 2; i < MAXN; i++){
        if(sieve[i]){
            greatestPFactor[i] = i;
            for(int x = i*2; x < MAXN; x+=i){
                sieve[x] = 0;
                greatestPFactor[x] = i;
            }
        }
    }
    for(int i = 2; i < MAXN; i++){
        numOfFactors[i] = numOfFactors[i / greatestPFactor[i]] + 1;
    }
}
