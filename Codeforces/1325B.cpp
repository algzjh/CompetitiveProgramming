# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<double, int> PDI;
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
        sort(a + 1, a + n + 1);
        int ans = unique(a + 1, a + n + 1) - (a + 1);
        printf("%d\n", ans);
    }
    return 0;
}
/*
可改编为求达到最长上升子序列所需的最少复制次数
*/
