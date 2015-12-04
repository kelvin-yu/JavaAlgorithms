#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define INF 1000000000
int tree[MAXN*4], data[MAXN];

void build(int index, int s, int e){
    if(s > e) return;
    if(s == e){
        tree[index] = data[s];
        return;
    }
    int mid = (s+e)/2;
    build(index * 2, s, mid);
    build(index * 2 + 1, mid + 1, e);
    tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
}

void update(int index, int s, int e, int pos, int val){
    if(s == e) tree[index] = val;
    else{
        int mid = (s+e)/2;
        if(pos <= mid)
            update(index * 2, s, mid, pos, val);
        else
            update(index * 2 + 1, mid + 1, e, pos, val);
        tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    }
}

int query(int index, int s, int e, int i, int j){
    if(s >= i && e <= j) return tree[index];
    else{
        int mid = (s+e)/2;
        int res = INF;
        if(mid >= i && s <= e)
            res = min(res, query(index * 2, s, mid, i, j));
        if(e >= i && mid+1 <= j)
            res = min(res, query(index * 2 + 1, mid + 1, e, i, j));
        return res;
    }
}

int main(){}
