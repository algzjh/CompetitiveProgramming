#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, d;
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        int ans = a[1];
        for(int i = 2; i <= n; ++i){
            if(a[i] == 0) continue;
            if(d < i - 1)  break;
            int canmove = min(a[i], d/(i - 1));
            ans += canmove;
            d -= canmove * (i - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
