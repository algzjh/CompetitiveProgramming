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
int n, s, k, a[MAXN];
map<int,bool> mp;

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        mp.clear();
        scanf("%d%d%d", &n, &s, &k);
        for(int i = 1; i <= k; ++i){
            scanf("%d", &a[i]);
            mp[a[i]] = true;
        }
        int ans = INF;
        for(int i = s; i >= max(1, s - 1000); --i){
            if(not mp[i]){
                ans = min(ans, abs(s - i));
            }
        }
        for(int i = s + 1; i <= min(n, s + 1000); ++i){
            if(not mp[i]){
                ans = min(ans, abs(s - i));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
100
3 3 2
3 2
 */
