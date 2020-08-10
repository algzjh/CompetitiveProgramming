#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 50 + 5;
const int MAXM = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[MAXN];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int p = 2;
        while(p <= n and a[p] - a[p - 1] <= 1)  ++p;
        printf("%s\n", p > n ? "YES" : "NO");
    }
    return 0;
}
