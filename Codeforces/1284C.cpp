#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(250005);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int A[MAXN];
 
void init(){
 
}
 
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    A[0] = 1;
    for(int i = 1; i <= n; ++i){
        A[i] = 1LL * A[i-1] * i % m;
    }
    LL ans = 0, tmp;
    for(int i = 1; i <= n; ++i){
        tmp = 1LL * (n - i + 1) * A[i] % m * A[n - i + 1] % m;
        ans = (ans + tmp) % m;
    }
    printf("%lld\n", ans);
    return 0;
}
