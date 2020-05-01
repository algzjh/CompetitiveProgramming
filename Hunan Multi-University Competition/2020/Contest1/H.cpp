#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
vector<int> G[MAXN];
int max_id;


struct Node{
    int v[2], p;
}nd[MAXN];


void dfs(int u, int fa){
    if(fa == 0){
        nd[u].v[0] = 1;
        nd[u].v[1] = 2;
        max_id = 2;
    }else{
        if(nd[fa].p == -1){
            nd[u].v[0] = nd[fa].v[0];
            nd[u].v[1] = max_id + 1;
            ++max_id;
            nd[fa].p = 0;
            nd[u].p = 0;
        }else{
            nd[u].v[0] = nd[fa].v[1];
            nd[u].v[1] = max_id + 1;
            ++max_id;
            nd[fa].p = 1;
            nd[u].p = 0;
        }
    }
    for(auto v : G[u]){
        if(v == fa) continue;
        dfs(v, u);
    }
}


void init(int n){
    max_id = 0;
    for(int i = 1; i <= n; ++i){
        nd[i].p = -1;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    init(n);
    int u, v;
    for(int i = 1; i <= n - 1; ++i){
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    if(n == 2){
        printf("1 2\n");
        printf("2 1\n");
        return 0;
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i){
        printf("%d %d\n", nd[i].v[0], nd[i].v[1]);
    }
    return 0;
}
/*
2
1 2


14
1 2
1 3
1 4
2 5
2 6
3 7
4 8
4 9
4 10
7 11
7 12
7 13
7 14

3
1 2
2 3
*/
