/*
 * consider the dfs tree
 * there are four edges:
 * tree edge, forward edge and back edge, and cross edge
 * we only need to consider back edge
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int col[MAXN], head[MAXN], tot;
int ans[MAXM], cnt;
 
struct Edge{
    int to, id, nxt;
}e[MAXM];
 
void addEdge(int u, int v, int id){
    e[tot].id = id;
    e[tot].to = v; e[tot].nxt = head[u]; head[u] = tot++;
}
 
void dfs(int u){
    col[u] = 1;
    for(int i = head[u]; i != -1; i = e[i].nxt){
        int v = e[i].to;
        if(col[v] == 0){
            ans[e[i].id] = 1;
            dfs(v);
        }else if(col[v] == 1){
            cnt = 2;
            ans[e[i].id] = 2;
        }else{
            ans[e[i].id] = 1;
        }
    }
    col[u] = 2;
}
 
void init(){
    memset(col, 0, sizeof(col));
    memset(head, -1, sizeof(head));
    tot = 0;
    cnt = 1;
}
 
int main(){
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    for(int i = 1; i <= m; ++i){
        scanf("%d%d", &u, &v);
        addEdge(u, v, i);
    }
    for(int i = 1; i <= n; ++i){
        if(col[i] == 0){
            dfs(i);
        }
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= m; ++i){
        if(i != 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
