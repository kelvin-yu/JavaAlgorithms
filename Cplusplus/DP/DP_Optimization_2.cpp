//COMMANDO
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

#define MAXN 1000001

int T, N;
ll a, b, c;
ll arr[MAXN];
ll sum[MAXN];
ll dp[MAXN];
vector<ll> M;
vector<ll> B;
int pointer = 0;

bool bad(int l1, int l2, int l3){
    return (B[l1] - B[l2]) * (M[l3] - M[l1]) > (B[l1] - B[l3]) * (M[l2] - M[l1]);
}

void add(ll m, ll b){
    M.pb(m);
    B.pb(b);
    while(M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)){
        M.erase(M.end() - 2);
        B.erase(B.end() - 2);
    }
}

ll query(ll x){
    if(pointer >= M.size())
        pointer = M.size() - 1;
    while(pointer < M.size() - 1 && M[pointer + 1] * x + B[pointer + 1] > M[pointer] * x + B[pointer])
        pointer++;
    return M[pointer] * x + B[pointer];
}

int main()
{
    IOS;
    cin >> T;
    while(T--){
        pointer = 0;
        M.clear();
        B.clear();
        memset(arr, 0, sizeof arr);
        memset(sum, 0, sizeof sum);
        memset(dp, 0, sizeof dp);
        cin >> N;
        cin >> a >> b >> c;
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
            sum[i] = arr[i] + sum[i-1];
        }
        dp[1] = a *  sum[1] * sum[1] + b * sum[1] + c;
        add(-2 * a * sum[1], dp[1] + a * sum[1] * sum[1] - b * sum[1]);
        for(int i = 2; i <= N; i++){
            dp[i] = a *  sum[i] * sum[i] + b * sum[i] + c;
            dp[i] = max(dp[i], a * sum[i] * sum[i] + b * sum[i] + c + query(sum[i]));
            add(-2 * a * sum[i], dp[i] + a * sum[i] * sum[i] - b * sum[i]);
        }
        cout << dp[N] << "\n";
    }
}


