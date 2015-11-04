#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
struct matrix{
    int a[MAXN][MAXN];
    matrix(){
        memset(a, 0, sizeof a);
    }
    matrix operator* (matrix b){
        matrix c;
        for(int k = 0; k < MAXN; k++){
            for(int i = 0; i < MAXN; i++){
                for(int j = 0; j < MAXN; j++){
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]);
                }
            }
        }
        return c;
    }
};

matrix pow_matrix(matrix a, int n){
    if(n == 1) return a;
    if(n % 2 == 0) return pow_matrix(a*a, n/2);
    else return a * pow_matrix(a*a, (n-1)/2);
}

int main(){

}
