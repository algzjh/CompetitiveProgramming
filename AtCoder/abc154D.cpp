#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
double p[MAXN], sum[MAXN];


int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%lf", &p[i]);
        p[i] = (1.0 + p[i]) / 2.0;
        sum[i] = sum[i-1] + p[i];
    }
    double ans = 0;
    for(int i = 1; i <= n - k + 1; ++i){
        ans = max(ans, sum[i + k - 1] - sum[i - 1]);
    }
    printf("%.10f\n", ans);
    return 0;
}
