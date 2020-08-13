/*
 * Author: algzjh
 * Date: 13/8/20
 * Comment: data structures, dfs, greedy, trees, two pointers, 2200
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
const LL INF = 1e18;
const int MOD = 998244353;
int leafNum[MAXN];
LL nowSum;
vector<LL> vec[2];

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

priority_queue<qnode, vector<qnode>, cmp> q[2];

struct Edge{
    int v, c;
    LL w;
    Edge(int _v=0, LL _w=0, int _c=0): v(_v), w(_w), c(_c){}
};

vector<Edge> G[MAXN];

void init(int n){
    for(int i = 1; i <= n; ++i){
        G[i].clear();
        leafNum[i] = 0;
    }
    for(int i = 0; i < 2; ++i){
        while(not q[i].empty()) q[i].pop();
        vec[i].clear();
    }
    nowSum = 0;
}

void dfs(int u, int rt){
    bool isLeaf = true;
    for(auto e: G[u]){
        int v = e.v;
        LL w = e.w;
        int c = e.c;
        if(v == rt)  continue;
        isLeaf = false;
        dfs(v, u);
        leafNum[u] += leafNum[v];
        q[c-1].push(qnode(w, leafNum[v]));
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
        int u, v, c;
        LL w;
        for(int i = 1; i <= n - 1; ++i){
            scanf("%d%d%lld%d", &u, &v, &w, &c);
            G[u].emplace_back(Edge(v, w, c));
            G[v].emplace_back(Edge(u, w, c));
        }
        dfs(1, 0);
        if(nowSum <= S){
            printf("0\n");
            continue;
        }
        for(int i = 0; i < 2; ++i){
            vec[i].emplace_back(0);
            LL tmpSum = nowSum;
            while(tmpSum > 0 and not q[i].empty()){
                qnode frt = q[i].top();
                q[i].pop();
                vec[i].emplace_back(vec[i][vec[i].size()-1] + frt.w * frt.t - frt.w/2 * frt.t);
                tmpSum -= frt.w * frt.t - frt.w/2 * frt.t;
                if(int(frt.w/2) > 0)  q[i].push(qnode(frt.w/2, frt.t));
            }
        }
        LL ans = INF;
        LL p = vec[1].size() - 1;
        for(LL i = 0; i < vec[0].size(); ++i){
            while(p >= 0 and nowSum - vec[0][i] - vec[1][p] <= S){
                ans = min(ans, i + p * 2);
                --p;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
4
5 50
1 3 100 1
1 5 10 2
2 3 123 2
5 4 55 1

4
2 100
1 2 409 2

20
10 36
5 1 6 2
8 1 4 1
4 1 8 1
9 1 10 1
3 1 6 1
2 1 2 2
6 1 2 1
10 1 2 1
7 2 9 1
 */
