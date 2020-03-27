# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const LL INF = 1e18;
typedef long long LL;
typedef pair<double, int> PDI;
LL a[MAXN];
char ans[MAXN];
 
 
void init(){
    a[0] = 0;
    for(LL i = 1; i <= 100000; ++i){
        a[i] = (1 + i) * i / 2;
    }
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    init();
    while(_--){
        LL n, k;
        scanf("%lld%lld", &n, &k);
        for(int i = 1; i <= n; ++i)  ans[i] = 'a';
        ans[n + 1] = '\0';
        int p = lower_bound(a + 1, a + 100001, k) - (a + 1);
        if(a[p] == k){
            ans[n + 1 - p] = 'b';
            ans[n + 1 - (p + 1)] = 'b';
        }else{
            k -= a[p];
            ans[n + 1 - k] = 'b';
            ans[n + 1 - (p + 2)] = 'b';
        }
        printf("%s\n", ans + 1);
    }
    return 0;
}
