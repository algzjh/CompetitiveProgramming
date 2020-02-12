#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN], k;
int dp[MAXN][4][2];
/*
digit dp

dp[i][j][r]: the higher i digits has already been decided,
and there are j non-zero digits,
r = 0: it has already been determined that it is less than N,
r = 1: it has not yet determined that it is less than N.
 */



int main() {
    scanf("%s%d", s + 1, &k);
    int len = strlen(s + 1);
    dp[0][0][1] = 1;
    for(int i = 1; i <= len; ++i){
        for(int j = 0; j <= k; ++j){
            for(int r=0; r <= 1; ++r){
                int up = r ? s[i] - '0' : 9;
                if(j == k)  up = 0;
                for(int h = 0; h <= up; ++h){
                    dp[i][j + (h!=0)][r&&(h==up)] += dp[i-1][j][r];
                }
            }
        }
    }
    printf("%d\n", dp[len][k][0] + dp[len][k][1]);
    return 0;
}
