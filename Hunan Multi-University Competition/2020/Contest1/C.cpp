#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int p[MAXN], sum[MAXN], dp[MAXN][25];


int getRound(int x){
    int r = x%10;
    if(r <= 4){
        return x - r;
    }else{
        return x + (10 - r);
    }
}


void init(){
    memset(dp, -1, sizeof(dp));
}


int main(){
    init();
    int n, d;
    scanf("%d%d", &n, &d);
    sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &p[i]);
        sum[i] = sum[i-1] + p[i];
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){ // item
        int max_group = min(d + 1, i);
        for(int j = 1; j <= max_group; ++j){ // group
            if(j == 1){
                dp[i][j] = getRound(sum[i]);
            }else{
                for(int k = j - 1; k <= i - 1; ++k){
                    if(dp[k][j-1] != -1){
                        if(dp[i][j] == -1)
                            dp[i][j] = dp[k][j-1] + getRound(sum[i] - sum[k]);
                        else
                            dp[i][j] = min(dp[i][j], dp[k][j-1] + getRound(sum[i] - sum[k]));
                    }
                }
            }
        }
    }
    int ans = INF;
    for(int j = 1; j <= min(d + 1, n); ++j){
        if(dp[n][j] != -1){
            ans = min(ans, dp[n][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
5 1
13 21 55 60 42

5 2
1 1 1 1 1
*/
