# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n, f[MAXN];
vector<int> G[MAXN], diameter;

PII dfs(int u, int fa, int dist){
    f[u] = fa;
    PII res = mk(dist, u);
    for(auto v : G[u]){
        if(v == fa) continue;
        res = max(res, dfs(v, u, dist + 1));
    }
    return res;
}

void bfs(){
    queue<int> q;
    vector<int> d(n + 1, -1);
    for(auto u : diameter){
        d[u] = 0;
        q.push(u);
    }
    while(not q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : G[u]){
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    PII ma = mk (-INF, 0);
    for(int i = 1; i <= n; ++i){
        ma = max(ma, mk(d[i], i));
    }
    printf("%d\n", diameter.size() - 1 + ma.fi);
    printf("%d %d %d\n", diameter.front(), diameter.back(), ma.se);
}

void init(){
    for(int i = 1; i <= n; ++i){
        G[i].clear();
    }
    diameter.clear();
}

int main(){
    scanf("%d", &n);
    init();
    int u, v;
    for(int i = 1; i <= n-1; ++i){
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    PII pa = dfs(1, 0, 0);
    PII pb = dfs(pa.se, 0, 0);
    u = pb.se;
    while(u != pa.se){
        diameter.emplace_back(u);
        u = f[u];
    }
    diameter.emplace_back(pa.se);
    if(diameter.size() == n){
        printf("%d\n", n - 1);
        printf("%d %d %d\n",diameter.front(), diameter[1], diameter.back());
    }else{
        bfs();
    }
    return 0;
}
/*

*/
