# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
vector<int> G[MAXN];
int n, m, p[MAXN][MAXN];
vector<PII> edge;
map<PII, int> f;


struct Query{
    int u, v, g;
}q[MAXN];

void init(){
    for(int i = 1; i <= n; ++i){
        G[i].clear();
    }
    f.clear();
    edge.clear();
}


void dfs1(int r, int u, int fa){
    for(auto v : G[u]){
        if(v == fa) continue;
        p[r][v] = u;
        dfs1(r, v, u);
    }
}


void solve(int u, int v, int g){
    int fa, son = v;
    do{
        fa = p[u][son];
        f[mk(min(fa, son),max(fa, son))] = max(f[mk(min(fa, son),max(fa, son))], g);
        son = fa;
    }while(fa != u);
}


int getMi(int u, int v){
    int mi = 1000000;
    int fa, son = v;
    do{
        fa = p[u][son];
        mi = min(mi, f[mk(min(fa, son),max(fa, son))]);
        son = fa;
    }while(fa != u);
    return mi;
}

bool check(){
    bool flag = true;
    for(int i = 1; i <= m; ++i){
        int mi = getMi(q[i].u, q[i].v);
        if(mi != q[i].g){
            flag = false;
            break;
        }
    }
    return flag;
}



int main(){
    scanf("%d", &n);
    init();
    int u, v, g;
    for(int i = 1; i <= n - 1; ++i){
        scanf("%d%d", &u, &v);
        if(u > v)  swap(u, v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        f[mk(u, v)] = 0;
        edge.emplace_back(mk(u, v));
    }
    for(int i = 1; i <= n; ++i){
        dfs1(i, i, 0);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
        scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].g);
        solve(q[i].u, q[i].v, q[i].g);
    }
    for(int i = 0; i < n - 1; ++i){
        if(f[mk(edge[i].fi, edge[i].se)] == 0){
            f[mk(edge[i].fi, edge[i].se)] = 1000000;
        }
    }
    if(check()){
        for(int i = 0; i < n - 1; ++i){
            if(i != 0)  printf(" ");
            printf("%d", f[mk(edge[i].fi, edge[i].se)]);
        }
        printf("\n");
    }else{
        printf("-1\n");
    }
    return 0;
}
