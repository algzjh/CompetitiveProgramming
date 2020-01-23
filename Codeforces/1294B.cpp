# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
PII p[MAXN];
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &p[i].fi, &p[i].se);
            if(p[i].fi < 0){
                flag = false;
            }
        }
        string ans = "";
        if(flag){
            PII pre = mk(0, 0);
            sort(p + 1, p + n + 1);
            for(int i = 1; i <= n; ++i){
                if(pre.fi == p[i].fi){
                    for(int j = pre.se + 1; j <= p[i].se; ++j){
                        ans += "U";
                    }
                }else if(pre.se > p[i].se){
                    flag = false;
                    break;
                }else{
                    for(int j = pre.fi + 1; j <= p[i].fi; ++j){
                        ans += "R";
                    }
                    for(int j = pre.se + 1; j <= p[i].se; ++j){
                        ans += "U";
                    }
                }
                pre = p[i];
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
        if(flag){
            cout << ans << endl;
        }
    }
    return 0;
}
