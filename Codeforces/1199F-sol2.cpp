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
    memset(sum, 0, sizeof(sum));
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
    for(int lenx = 1; lenx <= n; ++lenx){
        for(int leny = 1; leny <= n; ++leny){
            for(int x1 = 1; x1 <= n - lenx + 1; ++x1){
                int x2 = x1 + lenx - 1;
                for(int y1 = 1; y1 <= n - leny + 1; ++y1){
                    int y2 = y1 + leny - 1;
                    if(sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1] == 0){
                        dp[x1][x2][y1][y2] = 0;
                        continue;
                    }
                    int& ret = dp[x1][x2][y1][y2];
                    ret = max(x2-x1+1, y2-y1+1);
                    for(int i = x1; i < x2; ++i) ret = min(ret, dp[x1][i][y1][y2] + dp[i+1][x2][y1][y2]);
                    for(int j = y1; j < y2; ++j) ret = min(ret, dp[x1][x2][y1][j] + dp[x1][x2][j+1][y2]);
                }
            }
        }
    }
    printf("%d\n", dp[1][n][1][n]);
    return 0;
}
