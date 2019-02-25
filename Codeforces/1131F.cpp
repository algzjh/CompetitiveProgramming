#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e6+5;
const int MOD = 1e9+7;
typedef long long LL;
vector<int> G[MAXN];
int n, fa[MAXN];


int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

int main() {
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; ++i)  fa[i] = i;
        for(int i = 1; i <= n; ++i)  G[i].push_back(i);
        int u, v, fu, fv, ansid;
        for(int i = 1; i <= n - 1; ++i){
            scanf("%d%d", &u, &v);
            fu = Find(u);
            fv = Find(v);
            if(G[fv].size() > G[fu].size())  swap(fu, fv);
            fa[fv] = fu;
            ansid = fu;
            for(int item : G[fv])  G[fu].push_back(item);
        }
        bool first = true;
        for(int v : G[ansid]){
            if(!first) printf(" ");
            else first = false;
            printf("%d",  v);
        }
        for(int i = 1; i <= n; ++i)  G[i].clear();
    }
    return 0;
}
