#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 805;
const int MAXM = 2e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
LL dist[MAXN][MAXN];
vector<int> v;
vector<LL> ans;
 
struct Edge{
    int u, v, w;
}e[MAXM];
 
bool cmp(const Edge &e1, const Edge &e2){
    return e1.w < e2.w;
}
 
void init(){
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 1; i <= 800; ++i)  dist[i][i] = 0;
    v.clear();
    ans.clear();
}
 
int main(){
    init();
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; ++i){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1; i <= min(m, k); ++i){
        v.emplace_back(e[i].u);
        v.emplace_back(e[i].v);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int tu, tv;
    for(int i = 1; i <= min(m, k); ++i){
        tu = lower_bound(v.begin(), v.end(), e[i].u) - v.begin() + 1;
        tv = lower_bound(v.begin(), v.end(), e[i].v) - v.begin() + 1;
        dist[tu][tv] = e[i].w;
        dist[tv][tu] = e[i].w;
    }
    int sz = v.size();
    for(int k = 1; k <= sz; ++k){
        for(int i = 1; i <= sz; ++i){
            for(int j = 1; j <= sz; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= sz; ++i){
        for(int j = 1; j < i; ++j){
            ans.emplace_back(dist[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%lld\n", ans[k - 1]);
    return 0;
}
