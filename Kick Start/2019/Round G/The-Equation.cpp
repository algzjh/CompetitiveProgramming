#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e3 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef unsigned long long LL;
typedef pair<int, int> PII;
LL a[MAXN];
LL zero[55], one[55], f[55];

void init(){
    memset(zero, 0, sizeof(zero));
    memset(one, 0, sizeof(one));
    memset(f, 0, sizeof(f));
}

int main(){
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        init();
        int n, len = 52;
        LL m;
        scanf("%d%lld", &n, &m);
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i]);
            for(int j = 0; j <= len; ++j){
                if(a[i] & (1LL<<j))  ++one[j];
                else  ++zero[j];
            }
        }
//        for(int i = 0; i <= len; ++i){
//            cout << i << " : " << one[i] << " " << zero[i] << endl;
//        }
        f[0] = min(one[0], zero[0]);
        for(int i = 1; i <= len; ++i){
            if(one[i] > zero[i])  f[i] = f[i-1] + (1LL<<i) * zero[i];
            else  f[i] = f[i-1] + (1LL<<i) * one[i];
        }
//        for(int i = 0; i <= len; ++i){
//            cout << i << " : " << f[i] << endl;
//        }
        LL ans = 0, presum = 0;
        bool flag = false;
        for(int i = len; i >= 0 && presum <= m ; --i){
            if(i > 0){
                if(presum + (1LL<<i) * zero[i] + f[i-1] <= m)  presum += (1LL<<i) * zero[i], ans += (1LL<<i);
                else presum += (1LL<<i) * one[i];
            }else{
                if(presum + 1 * zero[0] <= m)  presum += 1 * zero[0], ans += 1;
                else presum += one[i];
            }
        }
        printf("Case #%d: ", cas++);
        if(presum <= m){
            printf("%lld\n", ans);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
