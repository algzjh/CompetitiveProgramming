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
int h[MAXN];
vector<int> v;
 
 
int main(){
    int n, a, b, k;
    scanf("%d%d%d%d", &n, &a, &b, &k);
    int ans = 0, remain;
    v.clear();
    for(int i = 1; i <= n; ++i){
        scanf("%d", &h[i]);
        if(h[i]%(a + b) >= 1 and h[i]%(a + b) <= a){
            ++ans;
        }else{
            remain = (h[i]%(a + b));
            if(remain == 0)  remain += a + b;
            remain -= a;
//            remain = h[i] - (h[i]/(a + b)) * (a + b) - a;
            int cnt = int(ceil(1.0 * remain / a));
            v.emplace_back(cnt);
        }
    }
    sort(v.begin(), v.end());
    int sz = v.size();
    for(int i = 0; i < sz; ++i){
        if(k >= v[i]){
            k -= v[i];
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
