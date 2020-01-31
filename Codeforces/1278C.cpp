# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN], n;
int pf[MAXN], sf[MAXN];
map<int, bool> existed;
map<int, int> mp;


void init(){
    pf[0] = sf[2 * n + 1] = 0;
    mp.clear();
    existed.clear();
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%d", &n);
        init();
        for(int i = 1; i <= 2 * n; ++i){
            scanf("%d", &a[i]);
        }
        existed[0] = true;
        mp[0] = 0;
        // red - blue
        for(int i = 1; i <= n; ++i){
            pf[i] = pf[i-1];
            if(a[i] == 1)  pf[i] += 1;
            else pf[i] -= 1;
            existed[pf[i]] = true;
            mp[pf[i]] = i;
        }
        int ans = 2 * n + 1 - mp[0] - 1;
        for(int i = 2 * n; i >= n + 1; --i){
            sf[i] = sf[i+1];
            if(a[i] == 1)  sf[i] += 1;
            else sf[i] -= 1;
            if(existed[-sf[i]]){
                ans = min(ans, i - mp[-sf[i]] - 1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
