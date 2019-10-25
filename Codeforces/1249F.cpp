/*
 * complexity: O(N^3)
 * Let child_i denote the number of children of the i-th node
 * the total time taken at the i-th node is O(N*(child_i)^2)
 * so the time complexity of the algorithm becomes
 * sum(N*(child_i)^2) = N * sum((child_i)^2) <= N * (sum(child_i))^2 = N^3
 */
#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(205);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN], dp[MAXN][MAXN];
vector<int> G[MAXN];
int n, k;
 
void init(int n){
    for(int i = 1;i <= n; ++i){
        G[i].clear();
    }
}
 
void dfs(int u, int fa){
    dp[u][0] = a[u];
    for(auto v : G[u]){
        if(v == fa) continue;
        dfs(v, u);
    }
    for(auto v : G[u]){
        if(v == fa) continue;
        dp[u][0] += dp[v][k-1];
    }
    for(int step = 1; step < MAXN; ++step){
        for(auto v : G[u]){
            if(v == fa) continue;
            int tmp = dp[v][step-1];
            for(auto w : G[u]){
                if(w == v || w == fa) continue;
                tmp += dp[w][max(step-1, k-step-1)];
            }
            dp[u][step] = max(dp[u][step], tmp);
        }
    }
    for(int step = MAXN - 1; step > 0; --step){
        dp[u][step-1] = max(dp[u][step-1], dp[u][step]);
    }
}
 
int main(){
    scanf("%d%d", &n, &k);
    ++k;
    init(n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    int u, v;
    for(int i = 1; i <= n-1; ++i){
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1, 0);
//    for(int i = 1; i <= 7; ++i){
//        for(int j = 0; j <= 7; ++j){
//            cout << "i: " << i << " j: " << j << " : " << dp[i][j] << endl;
//        }
//    }
    printf("%d\n", dp[1][0]);
    return 0;
}
