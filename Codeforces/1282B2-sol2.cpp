/**
 * 先从小到大排序
 * 最终买东西的段一定是连续的，否则可以向左平移，使得花费更少
 * 另外一定只有小于 k 个没有使用优惠券购买的商品，否则干嘛不使用呢？
 * 另外，这些没有使用优惠券购买的商品一定是最便宜的那些，这样花费更少~
 * 故只需枚举前面 k 个没有使用券的商品是哪些，然后 k 步跳就行了
 */
 
#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e5 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];
 
int main() {
    int cntTest;
    scanf("%d", &cntTest);
    for (int test = 0; test < cntTest; test++) {
        int n, p, k;
        scanf("%d%d%d", &n, &p, &k);
        int pref = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0; i <= k; i++) {
            int sum = pref;
            if (sum > p) break;
            int cnt = i;
            for (int j = i + k - 1; j < n; j += k) {
                if (sum + a[j] <= p) {
                    cnt += k;
                    sum += a[j];
                } else {
                    break;
                }
            }
            pref += a[i];
            ans = max(ans, cnt);
        }
        printf("%d\n", ans);
    }
}
/*
10
8 6 3
1 1 1 2 3 8 9 10
 
 
10
8 9 3
1 1 2 2 3 4 5 7
 */
