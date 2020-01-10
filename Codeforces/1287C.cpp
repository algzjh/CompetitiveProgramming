#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e2 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int p[MAXN], dp[MAXN][MAXN][MAXN][3];
int n;

int dfs(int pos, int odd, int even, int pre){
    if(pos == n + 1)  return 0;
    if(dp[pos][odd][even][pre] != -1)  return dp[pos][odd][even][pre];
    dp[pos][odd][even][pre] = 0;
    if(p[pos] != 0){
        if(p[pos]%2 == pre or pre == 2){
            dp[pos][odd][even][pre] = dfs(pos + 1, odd, even, p[pos]%2);
        }else{
            dp[pos][odd][even][pre] = dfs(pos + 1, odd, even, p[pos]%2) + 1;
        }
    }else{
        int to = MAXN, te = MAXN;
        if(pre == 2){
            if(odd > 0){
                to = dfs(pos + 1, odd - 1, even, 1);
            }
            if(even > 0){
                te = dfs(pos + 1, odd, even - 1, 0);
            }
        }else if(pre == 1){
            if(odd > 0){
                to = dfs(pos + 1, odd - 1, even, 1);
            }
            if(even > 0){
                te = dfs(pos + 1, odd, even - 1, 0) + 1;
            }
        }else if(pre == 0){
            if(odd > 0){
                to = dfs(pos + 1, odd - 1, even, 1) + 1;
            }
            if(even > 0){
                te = dfs(pos + 1, odd, even - 1, 0);
            }
        }
        dp[pos][odd][even][pre] += min(to, te);
    }
    return dp[pos][odd][even][pre];
}

int main(){
    scanf("%d", &n);
    int even = n/2, odd = n - even;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &p[i]);
        if(p[i] != 0){
            if(p[i] & 1)  --odd;
            else --even;
        }
    }
    memset(dp, -1, sizeof(dp));
//    cout << even << " " << odd << endl;
    printf("%d\n", dfs(1, odd, even, 2));
    return 0;
}
/*
3 4 6 7
 */
