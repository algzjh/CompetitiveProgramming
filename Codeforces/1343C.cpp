#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[MAXN];


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        LL sum = 0;
        int p = 1, q = 1;
        while(p <= n){
            int ma = a[p];
            int need_sign = a[p] > 0 ? 1 : -1;
            while(q + 1 <= n and a[q + 1] * need_sign > 0){
                ++q;
                ma = max(ma, a[q]);
            }
            sum += ma;
            p = ++q;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
