#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n; // even
        scanf("%d", &n);
        LL sum1 = 0, sum2 = 0;
        int now = 1;
        for(int i = 1; i <= n; ++i){
            now *= 2;
            if(i < n/2 or i == n)  sum1 += now;
            else sum2 += now;
        }
        printf("%lld\n", abs(sum1 - sum2));
    }
    return 0;
}
