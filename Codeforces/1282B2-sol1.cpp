# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN], dp[MAXN];
 
int main(){
    int _, n, p, k;
    scanf("%d", &_);
    while(_--){
        scanf("%d%d%d", &n, &p, &k);
        for(int i = 1; i <= n; ++i){
            dp[i] = INF;
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            dp[i] = dp[i-1] + a[i];
            if(i - k >= 0){
                dp[i] = min(dp[i], dp[i-k] + a[i]);
            }
        }
        int ans = 0;
        for(int i = n; i >= 1; --i){
            if(p >= dp[i]){
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
5 9 3
1 1 2 2 3 4 5 7
 
4
*/
