
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 500000
#define pb push_back

using namespace std;
//First character is null;
int sz = 1, trie[MAXN][26];
char t[MAXN];

void add(int cur, string word){
    if (word.length() > 0){
        int nxt = -1;
        if (trie[cur][word[0] - 'a'] == INF){
            trie[cur][word[0] - 'a'] = sz++;
            nxt = sz-1;
        }
        else{
            nxt = trie[cur][word[0] - 'a'];
        }
        t[nxt] = word[0];
        add(nxt, word.substr(1));
    }
}

void dfs(int cur){
    if(t[cur] != 0)
        cout << t[cur] << endl;
    for(int i = 0; i < 26; i++){
        if(trie[cur][i] != INF){
            dfs(trie[cur][i]);
        }
    }
}


int main(){
    memset(trie, 0x3f, sizeof trie);
    add(0, "world");
    add(0, "word");
    dfs(0);
}
