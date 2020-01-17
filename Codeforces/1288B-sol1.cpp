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
int a[10], A, B;
 
int count_digits(LL x){
    /*
     * 10^(j-1) <= x <= 10^j - 1
     * j-1 <= log10(x) < j
     * j-1 = floor(log10(x))
     * j = floor(log10(x)) + 1
     */
    return int(floor(log10(x))) + 1;
}
 
void init(){
    a[1] = 9;
    for(int i = 2; i <= 9; ++i){
        a[i] = a[i-1] * 10 + 9;
    }
}
 
int main() {
    init();
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%d%d", &A, &B);
        int t = upper_bound(a + 1, a + 10, B) - (a + 1);
//        cout << t << endl;
        printf("%lld\n", 1LL * A * t);
    }
    return 0;
}
