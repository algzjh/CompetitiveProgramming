#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int a[MAXN], cnt[MAXN], sum[MAXN];
 
 
void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
}
 
 
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    init();
    int ma = -INF, ans = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        ++cnt[a[i]];
        ma = max(ma, a[i]);
        ans += int(floor(log2(a[i])));
    }
    for(int i = 1; i <= ma; ++i){
        if(cnt[i] >= k){
            printf("0\n");
            return 0;
        }
    }
    sum[0] = 0;
    for(int i = 1; i <= ma; ++i)  sum[i] = sum[i-1] + cnt[i];
    int tc, tans, L, R, step;
    for(int i = 1; i <= ma; ++i){
        tc = cnt[i];
        tans = 0;
        L = R = i;
        step = 0;
        while(2 * L <= ma){
            L = 2 * L;
            R = min(ma, 2 * R + 1);
            ++step;
            if(tc + sum[R] - sum[L - 1] >= k){
                tans += step * (k - tc);
                tc = k;
                break;
            }else{
                tc += sum[R] - sum[L - 1];
                tans += step * (sum[R] - sum[L - 1]);
            }
        }
        if(tc >= k)  ans = min(ans, tans);
    }
    printf("%d\n", ans);
    return 0;
}
