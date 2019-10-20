#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1048576+5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[25], b[25];
LL s[MAXN], t[MAXN];

void init(){
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
}

int main(){
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        init();
        int n, h;
        scanf("%d%d", &n, &h);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &b[i]);
        }
        for(int i = 0; i < (1<<n); ++i){
            LL suma = 0, sumb = 0;
            for(int j = 0; j < n; ++j){
                if(i & (1<<j)){
                    suma += a[j];
                    sumb += b[j];
                }
            }
            s[i] = suma;
            t[i] = (sumb>=h);
        }
//        for(int i = 0; i < (1<<n); ++i){
//            cout << i << " : " << s[i] << endl;
//        }
//        for(int i = 0; i < (1<<n); ++i){
//            cout << i << " : " << t[i] << endl;
//        }
        for(int j = 0; j < n; ++j){
            for(int i = 0; i < (1<<n); ++i){
                if(!(i & (1<<j)))  t[i] += t[i | (1<<j)];
            }
        }
        LL ans = 0;
        int S = (1<<n) - 1;
        for(int i = 0; i < (1<<n); ++i){
            if(s[i] >= h){
                ans += t[S^i];
            }
        }
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}
