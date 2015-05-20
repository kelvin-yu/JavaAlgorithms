#include<bits/stdc++.h>
using namespace std;

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define INF                         (int)1e9
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define x                           first
#define y                           second
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define all(a)                      a.begin(), a.end()
#define DELREP(a)                   sort(all(a)); a.erase(unique(all(a)),a.end())
#define IOS                         ios::sync_with_stdio(0); cin.tie(0)

typedef long long ll;
typedef pair<int,int> pii;

template <typename T1, typename T2>
inline ostream&operator<<(ostream&os,const pair<T1, T2>&p){os<<"("<<p.x<<", "<<p.y<<")";}
template<typename T>
inline ostream&operator<<(ostream&os,const vector<T>&v){bool _=1;os<<"[";for(int i=0;i<v.size();i++){if(!_)os<<", ";os<<v[i];_= 0;}os<<"]";}
template<typename T>
inline ostream&operator<<(ostream&os,const set<T>&v){os<<"-BEGIN SET-\n";bool _=1;for(typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!_)os<<endl;os<<*ii;_= 0;}os<<"\n-END SET-";}
template<typename T>
inline ostream&operator<<(ostream&os,const unordered_set<T>&v){os<<"-BEGIN SET-\n";bool _= 1;for(typename unordered_set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!_)os<<endl;os<<*ii;_= 0;}os<<"\n--END SET--";}
template<typename T1, typename T2>
inline ostream&operator<<(ostream&os,const map<T1,T2>&v){os<<"-BEGIN MAP-\n";bool _= 1;for(typename map<T1, T2>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!_)os << endl;os<<" "<<*ii;_=0;}os<<endl<<"--END MAP--";}
template<typename T1, typename T2>
inline ostream&operator<<(ostream&os,const unordered_map<T1,T2>&v){os<<"-BEGIN MAP-\n";bool _= 1;for(typename unordered_map<T1, T2>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!_)os<<endl;os<<" "<<*ii;_=0;}os<<"\n--END MAP--";}

int main()
{

}
