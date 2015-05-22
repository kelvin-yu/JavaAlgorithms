#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000
int matrix[MAXN][MAXN];
int main()
{
    int N = 0;
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}
