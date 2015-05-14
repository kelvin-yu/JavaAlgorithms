#include<bits/stdc++.h>
#define MAXN 100000
#define inf 0x7fffffff
using namespace std;

int tree[MAXN * 4], lazy[MAXN * 4], data[MAXN];

void build(int index, int s, int e){
    if(s > e)
        return;
    if(s == e){
        tree[index] = data[s];
        return;
    }
    int mid = (s+e)/2;
    build(index * 2, s, mid);
    build(index * 2 + 1, mid + 1, e);
    tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
}

void modifyRange(int index, int s, int e, int i, int j, int value){
    if(lazy[index] != 0){
        tree[index] += lazy[index];
        if(s != e){
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(s > e || s > j || e < i)
        return;
    if(s >= i && e <= j){
        tree[index] += value;
        if(s != e){
            lazy[index * 2] += value;
            lazy[index * 2 + 1] += value;
        }
        return;
    }
    int mid = (s+e)/2;
    modifyRange(index * 2, s, mid, i, j, value);
    modifyRange(index * 2 + 1, mid + 1, e, i, j, value);
    tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
}

int query(int index, int s, int e, int i, int j){
    if(s > e || s > j || e < i) return -inf;
    if(lazy[index] != 0){
        tree[index] += lazy[index];
        if(s != e){
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(s >= i && e <= j)
        return tree[index];
    int mid = (s+e)/2;
    int l = query(index * 2, s, mid, i, j);
    int r = query(index * 2 + 1, mid + 1, e, i, j);
    return max(l, r);
}

int main()
{

}
