#include<bits/stdc++.h>
using namespace std;

string line;
int main(){
    int a, b, c, e;
    while(scanf("%d%d%d%d", &a, &b, &c, &e), (a || b || c || e)){
        int d = 1080;
        if(((double)(40-b+a)/(double)40)!=1)
            d += 360*((double)((40-b+a)%40)/(double)40);
        if(((double)((40+c-b)%40)/(double)40)!=1)
            d += 360*((double)((40+c-b)%40)/(double)40);
        if(((double)(40-e+c)/(double)40)!=1)
            d += 360*((double)((40-e+c)%40)/(double)40);
        cout << d << endl;
    }
}
