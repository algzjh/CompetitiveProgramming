/*
 * Codeforces Round 542
 * Connect
 * dfs
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 55;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, r1, c1, r2, c2;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
vector<PII> A, B;

bool check(int x, int y){
    if(x < 1 || x > n || y < 1 || y > n || s[x][y] == '1')  return false;
    return true;
}

void dfs(int x, int y, int op){
    if(vis[x][y])  return;
    vis[x][y] = true;
    if(op == 1)  A.emplace_back(mk(x, y));
    else  B.emplace_back(mk(x, y));
    int nx, ny;
    for(int i = 0; i <= 4; ++i){
        nx = x + dirx[i];
        ny = y + diry[i];
        if(check(nx, ny))  dfs(nx, ny, op);
    }
}

void init(){
    A.clear();
    B.clear();
}

int main() {
    while(~scanf("%d", &n)){
        init();
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        for(int i = 1; i <= n; ++i){
            scanf("%s", s[i] + 1);
        }
        memset(vis, 0, sizeof(vis));
        dfs(r1, c1, 1);
        memset(vis, 0, sizeof(vis));
        dfs(r2, c2, 2);
        int ans = INF, dx, dy;
        for(auto va : A){
            for(auto vb : B){
                dx = abs(va.fi - vb.fi);
                dy = abs(va.se - vb.se);
                ans = min(ans, dx * dx + dy * dy);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
