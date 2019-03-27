/*
 * Kickstart 2019 Round A
 * Training
 * prefix sum
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n, p, a[MAXN];
int sum[MAXN];

void init(){
    sum[0] = 0;
}

int main(){
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--){
        init();
        scanf("%d%d", &n, &p);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; ++i){
            sum[i] = sum[i - 1] + a[i];
        }
        int ans = INF;
        for(int i = p; i <= n; ++i){
            ans = min(ans, a[i]*p - sum[i] + sum[i - p]);
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
