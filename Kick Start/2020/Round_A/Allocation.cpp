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
int a[MAXN];


int main(){
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        int n, b;
        scanf("%d%d", &n, &b);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for(int i = 2; i <= n; ++i)  a[i] += a[i-1];
        int ans = upper_bound(a + 1, a + n + 1, b) - (a + 1);
        printf("Case #%d: %d\n",cas++, ans);
    }
    return 0;
}
