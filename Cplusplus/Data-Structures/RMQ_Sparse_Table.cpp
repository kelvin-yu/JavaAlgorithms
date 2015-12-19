#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define LOGMAXN 17
int data[MAXN];
int dp[MAXN][LOGMAXN];
int N;

void build(){
    for(int i = 0; i < N; i++)
        dp[i][0] = i;
    for(int j = 1; (1 << j) <= N; j++){
        for(int i = 0; i + (1 << j) - 1 < N; i++){
            if(data[dp[i][j-1]] < data[dp[i+(1<<(j-1))][j-1]])
                dp[i][j] = dp[i][j-1];
            else
                dp[i][j] = dp[i+(1<<(j-1))][j-1];
        }
    }
}

int query(int i, int j){
    int k = log2(j-i+1);
    if(data[dp[i][k]] < data[dp[j-(1<<k)+1][k]])
        return dp[i][k];
    else
        return dp[j-(1<<k)+1][k];
}

int main()
{

}
