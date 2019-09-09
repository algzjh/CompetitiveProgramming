#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int col[MAXN], head[MAXN], tot;
int ans[MAXM], cnt;
// one dollar = d rubles
// one euro = e rubles
// 1, 2, 5, 10, 20, 50, 100  dollar
// 5, 10, 20, 50, 100, 200  euro
 
 
int main(){
    int n, d, e;
    scanf("%d%d%d", &n, &d, &e); // [30, 100]
    int ans = n, up = n / (5 * e);
    for(int i = 0; i <= up; ++i){
        ans = min(ans, (n - i * 5 * e) % d);
    }
    printf("%d\n", ans);
    return 0;
}
