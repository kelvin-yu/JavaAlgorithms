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
int main()
{

}
