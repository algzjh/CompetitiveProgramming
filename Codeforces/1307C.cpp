#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
char s[MAXN];
LL cnt[26], dp[26][26];
 
 
void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
}
 
int main(){
    init();
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 26; ++j){
            dp[j][s[i] - 'a'] += cnt[j];
        }
        ++cnt[s[i] - 'a'];
    }
    LL ans = 0;
    for(int j = 0; j < 26; ++j){
        ans = max(ans, cnt[j]);
        for(int k = 0; k < 26; ++k){
            ans = max(ans, dp[j][k]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
/*
abababab
 */
