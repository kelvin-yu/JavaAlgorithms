#include<bits/stdc++.h>

using namespace std;

#define MAXN 5001
int dp[2][MAXN];
int N;
string s1, s2;
int main()
{
    int a = 0, b = 1;
    for(int i = s1.length()-1; i >= 0; i--){
        for(int j = s2.length()-1; j >= 0; j--){
            if(s1[i] == s2[j]){
                dp[a][j] = dp[b][j+1] + 1;
            }
            else{
                dp[a][j] = max(dp[b][j], dp[a][j+1]);
            }
        }
        swap(a, b);
    }
    cout << dp[b][0] << endl;
}
