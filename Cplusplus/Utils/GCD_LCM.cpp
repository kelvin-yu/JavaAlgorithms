#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  while(b != 0){
    ll temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

ll lcm(ll a, ll b){
  return a * b / gcd(a, b);
}

int main()
{

}
