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
char s[MAXN];
int dp[MAXN], ma[26];
 
 
void init(int n){
    for(int i = 1; i <= n; ++i){
        dp[i] = 1;
    }
    memset(ma, 0, sizeof(ma));
}
 
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    init(n);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int c = 25; c > s[i] - 'a'; --c){
            dp[i] = max(dp[i], ma[c] + 1);
        }
        ma[s[i]-'a'] = max(ma[s[i]-'a'], dp[i]);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    for(int i = 1; i <= n; ++i){
        if(i != 1)  printf(" ");
        printf("%d", dp[i]);
    }
    printf("\n");
    return 0;
}
