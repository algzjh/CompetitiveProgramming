#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MOD = 998244353;
LL a[MAXN], pow10[20], cnt[11];
static int look_table[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
 
void init(){
    pow10[0] = 1;
    for(int i = 1; i <= 19; ++i){
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    memset(cnt, 0 , sizeof(cnt));
}
 
int checkBitNum(LL x){
    for(int i = 9; i >= 0; --i){
        if(x >= look_table[i]) return i + 1;
    }
}
 
int main() {
    init();
    LL n;
    scanf("%lld", &n);
    LL ans = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &a[i]);
        ++cnt[checkBitNum(a[i])];
    }
    for(int i = 1; i <= n; ++i){
        LL pos = 1, bit;
        LL small = 0, largeorequal = 0, selfbit = checkBitNum(a[i]);
        for(int i = 1; i <= 10; ++i){
            if(i < selfbit) small += cnt[i];
            else largeorequal += cnt[i];
        }
        LL tmp = a[i];
        while(a[i] > 0){
            bit = a[i] % 10;
            ans = (ans + largeorequal * bit * pow10[(pos-1) * 2] % MOD) % MOD; // place on the right
            ans = (ans + largeorequal * bit * pow10[pos * 2 - 1] % MOD) % MOD; // place on the left
            ++pos;
            a[i]/=10;
        }
        a[i] = tmp;
        pos = 1;
        while(a[i] > 0){
            bit = a[i] % 10;
            for(int j = 1; j < selfbit; ++j){
                if(pos <= j){
                    ans = (ans + cnt[j] * bit * pow10[(pos-1) * 2] % MOD) % MOD;
                    ans = (ans + cnt[j] * bit * pow10[pos * 2 - 1] % MOD) % MOD;
                }else{
                    ans = (ans + 2 * cnt[j] * bit * pow10[2 * j - 1 + (pos - j)] % MOD) % MOD;
                }
            }
            ++pos;
            a[i] /= 10;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
