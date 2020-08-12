/*
 * Author: algzjh
 * Date: 12/8/20
 * Comment: data structures, dfs, greedy, trees, 2000
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int leafNum[MAXN];
LL nowSum;

struct qnode{
    LL w, t;
    qnode(LL _w=0, LL _t=0): w(_w), t(_t){}
};

struct cmp{
    bool operator()(const qnode& l, const qnode& r){
        // not l.w * l.t < r.w * r.t;
        return l.w * l.t - l.w/2 * l.t < r.w * r.t - r.w/2 * r.t;
    }
};

priority_queue<qnode, vector<qnode>, cmp> q;

struct Edge{
    int v;
    LL w;
    Edge(int _v=0, LL _w=0): v(_v), w(_w){}
};

vector<Edge> G[MAXN];

void init(int n){
    for(int i = 1; i <= n; ++i){
        G[i].clear();
        leafNum[i] = 0;
    }
    while(not q.empty())  q.pop();
    nowSum = 0;
}

void dfs(int u, int rt){
    bool isLeaf = true;
    for(auto e: G[u]){
        int v = e.v;
        LL w = e.w;
        if(v == rt)  continue;
        isLeaf = false;
        dfs(v, u);
        leafNum[u] += leafNum[v];
        q.push(qnode(w, leafNum[v]));
        nowSum += w * leafNum[v];
    }
    if(isLeaf)  leafNum[u] = 1;
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        LL S;
        scanf("%d%lld", &n, &S);
        init(n);
        int u, v;
        LL w;
        for(int i = 1; i <= n - 1; ++i){
            scanf("%d%d%lld", &u, &v, &w);
            G[u].emplace_back(Edge(v, w));
            G[v].emplace_back(Edge(u, w));
        }
        dfs(1, 0);
        LL ans = 0;
        while(nowSum > S){
            qnode frt = q.top();
            LL pre = frt.w * frt.t;
            LL now = frt.w/2 * frt.t;
            nowSum -= (pre - now);
            q.pop();
            q.push(qnode(frt.w/2, frt.t));
            ++ans;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
