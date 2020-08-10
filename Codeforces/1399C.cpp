/*
 * Author: algzjh
 * Date: 10/8/20
 * Comment:
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 50 + 5;
const int MAXM = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int w[MAXN], cnt[105];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &w[i]);
            ++cnt[w[i]];
        }
        int ans = 0;
        for(int i = 1; i <= 100; ++i){
            int tans = 0;
            for(int j = 1; j <= 50; ++j){
                if(i <= j)  continue;
                tans += min(cnt[j], cnt[i - j]);
            }
            ans = max(ans, tans);
        }
        printf("%d\n", ans/2);
    }
    return 0;
}
