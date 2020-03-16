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
int n, h, l, r;
int dp[2][MAXN];


void init(){
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
}


int main(){
    init();
    scanf("%d%d%d%d", &n, &h, &l, &r);
    int x, tim, cur = 0, sum = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        sum += x;
        cur ^= 1;
        for(int j = 0; j < i; ++j){
            if(dp[cur^1][j] >= 0){
                for(int k = j; k <= j + 1; ++k){
                    tim = (sum - k + h) % h;
                    dp[cur][k] = max(dp[cur][k], dp[cur^1][j] + (l <= tim and tim <= r));
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= n; ++j){
        ans = max(ans, dp[cur][j]);
    }
    printf("%d\n", ans);
    return 0;
}
