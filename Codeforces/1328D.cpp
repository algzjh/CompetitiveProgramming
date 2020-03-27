# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const LL INF = 1e18;
typedef long long LL;
typedef pair<double, int> PDI;
int t[MAXN], c[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &t[i]);
        }
        c[1] = 1;
        int k = 1;
        bool flag = false;
        int pos = 0;
        for(int i = 2; i <= n; ++i){
            if(t[i] == t[i-1]){
                c[i] = c[i-1];
                pos = i;
                flag = true;
            }else{
                if(c[i-1] == 1)  c[i] = c[i-1] + 1;
                else c[i] = c[i-1] - 1;
                k = max(k, c[i]);
            }
        }
        if(t[n] != t[1] and c[n] == c[1]){
            if(t[n] == t[n-1]){
                c[n] = 2;
            }else{
                if(flag){
                    c[n] = 2;
                    for(int i = pos; i <= n - 1; ++i){
                        c[i] = 3 - c[i];
                    }
                }
                else c[n] = 3;
            }
            k = max(k, c[n]);
        }
        printf("%d\n", k);
        for(int i = 1; i <= n; ++i){
            printf("%d%c", c[i], i == n ? '\n': ' ');
        }
    }
    return 0;
}
