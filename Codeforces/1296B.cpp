# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        LL s, ans = 0, tmp;
        scanf("%lld", &s);
        while(s > 0){
            if(s < 10){
                ans += s;
                s = 0;
            }else{
                tmp = s/10;
                ans += tmp * 10;
                s = s - tmp * 10 + tmp;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
