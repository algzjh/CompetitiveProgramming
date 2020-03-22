#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1500 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef unsigned long long LL;
typedef pair<int, int> PII;
int n, k, p;
int a[55][35], dp[MAXN];


void init(){
    dp[0] = 0;
    for(int i = 1; i <= p; ++i)  dp[i] = -INF;
}

int main(){
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        init();
        scanf("%d%d%d", &n, &k, &p);
        for(int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                scanf("%d", &a[i][j]);
                a[i][j] += a[i][j-1];
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = p; j >= 0; --j){
                for(int r = 0; r <= k; ++r){
                    if(j - r >= 0){
                        dp[j] = max(dp[j], dp[j - r] + a[i][r]);
                    }
                }
            }
        }
        printf("Case #%d: %d\n", cas++, dp[p]);
    }
    return 0;
}
