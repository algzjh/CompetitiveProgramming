#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e5 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
vector<int> G[MAXN];
set<PII> s;
bool vis[MAXN];
 
void init(int n){
    for(int i = 1; i <= n; ++i){
        G[i].clear();
        vis[i] = false;
    }
    s.clear();
}
 
PII dfs(int u, int fa, int& mi, int& ma){
    vis[u] = true;
    for(auto v : G[u]){
        if(v == fa || vis[v]) continue;
        mi = min(mi, v), ma = max(ma, v);
        dfs(v, u, mi, ma);
    }
    return mk(mi, ma);
}
 
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    int u, v;
    for(int i = 1; i <= m; ++i){
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            int tmi = i, tma = i;
            dfs(i, 0, tmi, tma);
            s.insert(mk(tmi, tma));
        }
    }
//    for(auto it : s){
//        cout << it.fi << " " << it.se << endl;
//    }
    LL ans = 0;
    int rightmost = 0;
    for(auto it: s){
        if(it.fi <= rightmost){
            ++ans;
        }
        rightmost = max(rightmost, it.se);
    }
    printf("%lld\n", ans);
    return 0;
}
/*
500 5
100 300
200 400
420 440
430 450
435 460
 */
