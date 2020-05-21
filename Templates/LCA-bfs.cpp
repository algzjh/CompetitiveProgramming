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
int n, head[MAXN];

struct Edge{
    int v, w, nxt;
}e[MAXM];

//LCA
int f[MAXN][20],d[MAXN],dist[MAXN];
int LOG = (int)(log(n)/log(2)) + 1;

void bfs(){//预处理
    queue<int> q;
    q.push(1);
    d[1]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt){
            int v=e[i].v;
            int w=e[i].w;
            if(d[v]) continue;
            d[v]=d[u]+1;
            dist[v]=dist[u]+w;
            f[v][0]=u;
            for(int j=1;j<=LOG;++j){
                f[v][j]=f[f[v][j-1]][j-1];
            }
            q.push(v);
        }
    }
}


int lca(int u,int v){//回答一个询问
    if(d[u]>d[v]) swap(u,v);//让v深度更大
    for(int i=LOG;i>=0;--i){
        if(d[f[v][i]]>=d[u]) v=f[v][i];
    }
    if(u==v) return u;
    for(int i=LOG;i>=0;--i){
        if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    }
    return f[u][0];
}

int main(){
    scanf("%d", &n);
    return 0;
}
/*

 */