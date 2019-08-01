#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 55;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
char s[MAXN];
int a[MAXN][MAXN], sum[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
 
void init(){
    memset(dp, -1, sizeof(dp));
    memset(sum, 0, sizeof(sum));
}
 
 
/*
 * (x1,y1)      (x1,y2)
 *
 * (x2,y1)      (x2,y2)
 */
int solve(int x1, int x2, int y1, int y2){
    if(sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1] == 0){
        return 0;
    }
    if(dp[x1][x2][y1][y2] >= 0) return dp[x1][x2][y1][y2];
    int ret = max(x2 - x1 + 1, y2 - y1 + 1);
    for(int i = x1; i <= x2-1; ++i){
        ret = min(ret, solve(x1, i, y1, y2) + solve(i+1, x2, y1, y2));
    }
    for(int j = y1; j <= y2-1; ++j){
        ret = min(ret, solve(x1, x2, y1, j) + solve(x1, x2, j + 1, y2));
    }
    return dp[x1][x2][y1][y2] = ret;
}
 
int main(){
    init();
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i){
        scanf("%s", s + 1);
        for(int j = 1; j <= n; ++j){
            a[i][j] = (s[j] == '#');
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
        }
    }
    printf("%d\n", solve(1, n, 1, n));
    return 0;
}
