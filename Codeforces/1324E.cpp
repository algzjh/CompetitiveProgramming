#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
int n, h, l, r, x, sum;
int dp[MAXN][MAXN];
 
 
void init(){
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    sum = 0;
}
 
 
int main(){
    init();
    scanf("%d%d%d%d", &n, &h, &l, &r);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        sum += x;
        int now;
        for(int j = 0; j < i; ++j){
            if(dp[i-1][j] >= 0){
                now = (sum - j) % h;
                dp[i][j] = max(dp[i][j], dp[i-1][j] + (l <= now and now <= r));
                now = (now - 1 + h) % h;
                dp[i][j + 1] = max(dp[i][j + 1], dp[i-1][j] + (l <= now and now <= r));
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= n; ++j){
        ans = max(ans, dp[n][j]);
    }
    printf("%d\n", ans);
    return 0;
}
