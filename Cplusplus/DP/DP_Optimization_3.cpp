//Logging Industry
#include<bits/stdc++.h>
#define __ENABLE_EXPERIMENTAL_TADPOLE_OPERATORS
using namespace std;

char _;
#define PI 3.14159265359
#define scan(x)                     while ((x=getchar())<'0'); for (x-='0';(_=getchar())>='0'; x = (x<<1)+(x<<3)+_-'0')
#define INF                         (int)2e9
#define LLINF                       LLONG_MAX
#define x                           first
#define y                           second
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof a)
#define mp                          make_pair
#define all(a)                      a.begin(), a.end()
#define COMPRESS(a)                 sort(all(a)); a.erase(unique(all(a)),a.end())
#define IOS                         ios::sync_with_stdio(0); cin.tie(0)
#define debug(args...)              {vector<string> v = split(#args, ',');err(v.begin(), args);}
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

vector<string> split(const string& s, char c){vector<string> v;stringstream st(s);string x;while(getline(st, x, c))v.pb(x);return move(v);}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {cerr<<it->substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}
template <typename T1, typename T2>
inline ostream&operator<<(ostream&os,const pair<T1, T2>&p){return os<<"("<<p.x<<", "<<p.y<<")";}
template<typename T>
inline ostream&operator<<(ostream&os,const vector<T>&v){bool _=1;os<<"[";for(auto i:v){if(!_)os<<", ";os<<i;_= 0;}return os<<"]";}
template<typename T>
inline ostream&operator<<(ostream&os,const set<T>&v){os<<"-BEGIN SET-\n";bool _=1;for(auto i:v){if(!_)os<<"\n";os<<i;_= 0;}return os<<"\n-END SET-";}
template<typename T>
inline ostream&operator<<(ostream&os,const unordered_set<T>&v){os<<"-BEGIN SET-\n";bool _= 1;for(auto i:v){if(!_)os<<"\n";os<<i;_= 0;}return os<<"\n--END SET--";}
template<typename T1, typename T2>
inline ostream&operator<<(ostream&os,const map<T1,T2>&v){os<<"-BEGIN MAP-\n";bool _= 1;for(auto i:v){if(!_)os << "\n";os<<" "<<i;_=0;}return os<<"\n"<<"--END MAP--";}
template<typename T1, typename T2>
inline ostream&operator<<(ostream&os,const unordered_map<T1,T2>&v){os<<"-BEGIN MAP-\n";bool _= 1;for(auto i:v){if(!_)os<<endl;os<<" "<<i;_=0;}return os<<"\n--END MAP--";}

#define MAXN 100001
int n;
ll a[MAXN], b[MAXN];
ll dp[MAXN];
int pointer = 0;
vector<ll> M, B;

ld bad (int l, int r)
{
    return ((ld) B[r] - B[l]) / ((ld) M[l]- M[r]);
}

void add (ll m, ll b)
{
    M.pb(m);
    B.pb(b);
    while (M.size() >= 3 && bad(M.size() - 3, M.size() - 1) >= bad (M.size() - 2, M.size() - 1))
    {
        M.erase(M.end() - 2);
        B.erase(B.end() - 2);
    }
}

ll query(ll x){
    if(pointer >= M.size()){
        pointer = M.size() - 1;
    }
    while(pointer < M.size() - 1 && M[pointer + 1] * x + B[pointer + 1] < M[pointer] * x + B[pointer]){
        pointer++;
    }
    return M[pointer] * x + B[pointer];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    dp[0] = b[0];
    add(b[0], dp[0]);
    for(int i = 1; i < n; i++){
        dp[i] = query(a[i] - 1) + b[i];
        add(b[i], dp[i]);
    }
    cout << dp[n-1] << endl;
}
