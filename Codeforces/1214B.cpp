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
// red girl
// blue boy
// n+1 deck  i blue and n-i red
//boy girl
//0 n
//1 n-1
//...
//n 0
// x + y <= n
 
int main(){
    int b, g, n;
    scanf("%d%d%d", &b, &g, &n);
            int ans = 0;
            for(int i = 0; i <= b && i <= n; ++i){
        int tg = n - i;
        if(tg >= 0 && tg <= g) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
