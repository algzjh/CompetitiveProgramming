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
typedef pair<LL, LL> PLL;
int a[MAXN], b[MAXN], d[MAXN];


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
        d[i] = a[i] - b[i];
    }
    sort(d + 1, d + n + 1);
    LL ans = 0, add;
    for(int i = 1; i <= n; ++i){
        add = upper_bound(d + 1, d + n + 1, b[i] - a[i]) - (d + 1);
        add = n - add;
        if(a[i] > b[i])  --add;
        ans += add;
    }
    printf("%lld\n", ans/2);  // attention
    return 0;
}
