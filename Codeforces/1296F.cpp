# include <bits/stdc++.h>
# include <unordered_map>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n, m;
int head[MAXN], tot;
int dep[MAXN], pa[MAXN], f[MAXN];


struct Edge{
    int from, to, nxt;
    Edge(){}
    Edge(int _from, int _to): from(_from), to(_to){}
}e[MAXM * 2];


struct Query{
    int u, v, g;
}q[MAXM];

void addEdge(int u, int v){
    e[tot].from = u; e[tot].to = v;
    e[tot].nxt = head[u]; head[u] = tot++;
}

void dfs(int u, int fa){
    f[u] = 0;
    dep[u] = dep[fa] + 1;
    pa[u] = fa;
    for(int i = head[u]; i != -1; i = e[i].nxt){
        int v = e[i].to;
        if(v != fa)  dfs(v, u);
    }
}


void update(int u, int v, int g){
    while(u != v){
        if(dep[v] < dep[u])  swap(u, v);
        f[v] = max(f[v], g);
        v = pa[v];
    }
}

int getMi(int u, int v){
    int mi = 1000000;
    while(u != v){
        if(dep[v] < dep[u])  swap(u, v);
        mi = min(mi, f[v]);
        v = pa[v];
    }
    return mi;
}

bool check(){
    bool flag = true;
    for(int i = 1; i <= m; ++i){
        if(getMi(q[i].u, q[i].v) != q[i].g){
            flag = false;
            break;
        }
    }
    return flag;
}

void init(){
    tot = 0;
    for(int i = 1; i <= n; ++i){
        head[i] = -1;
    }
    dep[0] = 0;
}

int main(){
    scanf("%d", &n);
    init();
    int u, v;
    for(int i = 0; i < n - 1; ++i){
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 0);
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
        scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].g);
        update(q[i].u, q[i].v, q[i].g);
    }
    if(check()){
        for(int i = 0; i < n - 1; ++i){
            if(i != 0)  printf(" ");
            u = e[2 * i].from;
            v = e[2 * i].to;
            if(dep[v] < dep[u])  swap(u, v);
            printf("%d", f[v] == 0 ? 1000000 : f[v]);
        }
        printf("\n");
    }else{
        printf("-1\n");
    }
    return 0;
}
