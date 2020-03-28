#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int ans[MAXN], n;

struct Edge{
    int to, id;
};
vector<Edge> G[MAXN];


int main() {
    scanf("%d", &n);
    int u, v;
    for(int i = 1; i <= n - 1; ++i){
        scanf("%d%d", &u, &v);
        G[u].emplace_back(Edge{v, i});
        G[v].emplace_back(Edge{u, i});
        ans[i] = -1;
    }
    bool flag = false;
    for(int i = 1; i <= n; ++i){
        if(G[i].size() >= 3){
            for(int j = 0; j < 3; ++j){
                int id = G[i][j].id;
                ans[id] = j;
            }
            flag = true;
            break;
        }
    }
    int now = 0;
    if(flag)  now = 3;
    for(int i = 1; i <= n - 1; ++i){
        if(ans[i] == -1){
            ans[i] = now;
            ++now;
        }
    }
    for(int i = 1; i <= n - 1; ++i){
        printf("%d\n", ans[i]);
    }
    return 0;
}
/*
7
6 4
3 7
3 5
1 3
4 2
7 4
 */
