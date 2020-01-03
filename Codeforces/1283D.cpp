#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int x[MAXN];
int dir[2] = {-1, 1};
map<int, bool> vis;
map<int, int> fa;
queue<int> q;
vector<int> ans;
int cnt = 0;


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vis.clear();
    fa.clear();
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x[i]);
        q.push(x[i]);
        vis[x[i]] = true;
        fa[x[i]] = x[i];
    }
    while(not q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < 2; ++i){
            int v = u + dir[i];
            if(not vis[v]){
                ans.emplace_back(v);
                fa[v] = fa[u];
                q.push(v);
                vis[v] = true;
                ++cnt;
                if(cnt == m) break;
            }
        }
        if(cnt == m) break;
    }
    LL sum = 0;
    for(int i = 0; i < m; ++i){
        sum += abs(fa[ans[i]] - ans[i]);
    }
    printf("%lld\n", sum);
    for(int i = 0; i < m; ++i){
        if(i != 0)  printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
/*
*/
