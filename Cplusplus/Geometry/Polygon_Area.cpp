#include<bits/stdc++.h>
using namespace std;
#define x first
#define y first

//shoelace formula
double polygon_area(int N, pair<double,double>* P){
    double area = 0;
    for(int i = 0; i < N; i++){
        int j = (i+1) % N;
        area += P[i].x * P[j].y;
        area -= P[j].x * P[i].y;
    }
    area /= 2.0;
    return area;
}

int main()
{

}
