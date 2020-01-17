#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e5 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int A, B;
 
int count_digits(int x){
    /*
     * 10^(j-1) <= x <= 10^j - 1
     * j-1 <= log10(x) < j
     * j-1 = floor(log10(x))
     * j = floor(log10(x)) + 1
     */
    return int(floor(log10(x))) + 1;
}
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%d%d", &A, &B);
        printf("%lld\n", 1LL * A * (count_digits(B + 1) - 1));
    }
    return 0;
}
