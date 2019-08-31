#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int fa[MAXN], sz[MAXN];
LL a[MAXN];
 
struct Edge{
    int u, v, w;
}e[MAXM];
 
bool cmp(const Edge &e1, const Edge &e2){
    return e1.w < e2.w;
}
 
struct Query{
    int c, id;
}q[MAXN];
 
bool cmp2(const Query &u, const Query &v){
    return u.c < v.c;
}
 
int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
 
int Union(int x, int y){
    fa[x] = y;
    sz[y] += sz[x];
}
 
void init(int n){
    for(int i = 1; i <= n; ++i){
        fa[i] = i;
        sz[i] = 1;
    }
}
 
LL calc(int x){
    if(sz[x] == 1)  return 0;
    return (1LL * sz[x] * (sz[x] - 1)) >> 1;
}
 
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for(int i = 1; i <= n-1; ++i){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    sort(e + 1, e + n, cmp);
    for(int i = 1; i <= m; ++i){
        scanf("%d", &q[i].c);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp2);
    LL ans = 0;
    int p = 0, u, v, fu, fv;
    for(int i = 1; i <= m; ++i){
        while(p + 1 <= n - 1 && e[p+1].w <= q[i].c){
            ++p;
            u = e[p].u, v = e[p].v;
            fu = Find(u), fv = Find(v);
            ans = ans - calc(fu) - calc(fv);
            Union(fu, fv);
            ans = ans + calc(fv);
        }
        a[q[i].id] = ans;
    }
    for(int i = 1; i <= m; ++i){
        if(i != 1)  printf(" ");
        printf("%lld", a[i]);
    }
    printf("\n");
    return 0;
}
