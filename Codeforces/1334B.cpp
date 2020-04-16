#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
int a[MAXN];
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int n, x;
        scanf("%d%d", &n, &x);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1, greater<int>());
        LL sum = 0, need = 0;
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            sum += a[i];
            need += x;
            if(sum < need){
                break;
            }
            ans = max(ans, i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
