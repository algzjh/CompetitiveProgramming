#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e5 + 5);
const int MAXM = static_cast<const int>(2e6 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
const int BIAS = 1e6;
typedef long long LL;
typedef pair<int, int> PII;
LL a[MAXN], b[MAXN];
 
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i){
        b[i] += a[i];
        if(i + m <= n)  b[i + m] += b[i];
    }
    LL pre = 0;
    for(int i = 1; i <= n; ++i){
        if(i != 1)  printf(" ");
        printf("%lld", pre + b[i]);
        pre += b[i];
    }
    printf("\n");
    return 0;
}
