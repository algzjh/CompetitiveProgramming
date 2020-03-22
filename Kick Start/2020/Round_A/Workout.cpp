#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef unsigned long long LL;
typedef pair<int, int> PII;
int a[MAXN], n, k;


bool check(int dif){
    int need = 0, add;
    for(int i = 2; i <= n; ++i){
        add = int(ceil(1.0 * (a[i] - a[i-1]) / dif)) - 1;
        need += add;
        if(need > k)  return false;
    }
    return true;
}

int main(){
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        scanf("%d%d", &n, &k);
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(i > 1)  ans = max(ans, a[i] - a[i-1]);
        }
        int L = 1, R = ans, mid;
        while(L <= R){
            mid = (L + R) / 2;
            if(check(mid)){
                R = mid - 1;
                ans = min(ans, mid);
            }else{
                L = mid + 1;
            }
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
