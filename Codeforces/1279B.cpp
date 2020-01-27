# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, s;
        scanf("%d%d", &n, &s);
        LL sum = 0;
        int ma = -INF, p, ans = 0;
        bool flag = false;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(flag) continue;
            sum += a[i];
            if(ma < a[i] ){
                ma = a[i];
                p = i;
            }
            if(sum > s){
                if(sum - ma > s){
                    flag = true;
                }else{
                    ans = p;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
