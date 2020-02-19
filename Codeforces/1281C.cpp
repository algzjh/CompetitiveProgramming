#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 500 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
char s[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int x;
        scanf("%d%s", &x, s + 1);
        int n = strlen(s + 1);
        LL ans = n;
        vector<char> v(s + 1, s + n + 1);
        for(int i = 1; i <= x; ++i){
            int replicate = v[i - 1] - '1';
            if(v.size() < x){
                vector<char> suf(v.begin() + i, v.end());
                for(int j = 1; j <= replicate; ++j){
                    v.insert(v.end(), suf.begin(), suf.end());
                }
            }
            ans = (ans + (ans - i + MOD) % MOD * replicate % MOD) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
