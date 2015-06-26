#include<algorithm>

using namespace std;

#define MAXN 100
int id[MAXN];
int size[MAXN];
void build(){
    for(int i = 0; i < MAXN; i++){
        id[i] = i;
        size[i] = 1;
    }
}
int ufind(int x){
    int root = x;
    if(root != id[x]){
        root = id[root];
    }
    while(root != x){
        int temp = id[x];
        id[x] = root;
        x = temp;
    }
    return root;
}
void umerge(int a, int b){
    int i = ufind(a);
    int j = ufind(b);
    if(i == j) return;
    if(size[i] > size[j]){
        id[j] = i;
        size[i] += size[j];
    }
    else{
        id[i] = j;
        size[j] += size[i];
    }
}
vector<pair<int, pair<int, int> > > edges;
int nodes;
int main()
{
    /* Read adjacency list */
    int num = 0;
    int mst = 0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++){
        if(nodes == num)
            break;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(ufind(a) != ufind(b)){
            umerge(a, b);
            mst += edges[i].first;
            num++;
        }
    }
}
