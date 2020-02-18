#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, x;
        scanf("%d%d", &n, &x);
        int ma = 0;
        bool hasx = false;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            ma = max(a[i], ma);
            if(a[i] == x)  hasx = true;
        }
        if(hasx)  printf("1\n");
        else{
            int ans = x / ma;
            if(ma > x)  ++ans;
            if(x % ma != 0)  ++ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}
/*
 
15
 */
