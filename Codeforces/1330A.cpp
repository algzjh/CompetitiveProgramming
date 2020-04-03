#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e2 + 5;
const int MOD = 998244353;
int a[MAXN];
bool vis[MAXN];
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        memset(vis, false, sizeof(vis));
        int n, x;
        scanf("%d%d", &n, &x);
        for(int i = 1; i <= n; ++i){
           scanf("%d", &a[i]);
           vis[a[i]] = true;
        }
        int ans = 0;
        for(int i = 1; i <= 205; ++i){
            if(not vis[i]){
                if(x <= 0){
                    break;
                }else{
                    --x;
                }
            }
            ans = max(ans, i);
        }
        printf("%d\n", ans);
    }
}
