#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244853;
const int INF = 0x3f3f3f3f;
LL n, a, b;
char s[MAXN];
vector<PII> v;
int p;
 
void init(){
    v.clear();
}
 
LL calc0(int x, int op){
    if(op == 1){
        return 1LL * (x + 2) * a + (x - 1) * b;
    }else{
        return 1LL * x * a + (x - 1) * 2 * b;
    }
}
 
 
LL calc1(int x){
    return 1LL * (x + 1) * 2 * b + x * a;
}
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        init();
        // a pipeline
        // b pillar
        scanf("%lld%lld%lld", &n, &a, &b);
        scanf("%s", s + 1);
        int n = strlen(s + 1);
 
        bool allzero = true;
        for(int i = 1; i <= n; ++i){
            if(s[i] == '1'){
                allzero = false;
                break;
            }
        }
 
        if(allzero){
            printf("%lld\n", 1LL * (n + 1) * b + n * a);
            continue;
        }
 
        LL ans = 0;
 
        for(int i = 1; i <= n;){
            int j = i + 1;
            while(j <= n && s[j] == s[j-1]) ++j;
            v.emplace_back(mk(s[i], j - i));
            i = j;
        }
        int p = int(floor( (2.0*a + b)/b ));
//        if(p == 1) --p;
//        cout << "p: " << p << endl;
        int sz = v.size();
 
//        for(int i = 0; i < sz; ++i){
//            cout << char(v[i].fi) << " " << v[i].se << endl;
//        }
 
        for(int i = 0; i < sz; ++i){
            if(v[i].fi == '0'){
                if(i == 0 || i == sz -1){
                    ans += 1LL * (v[i].se + 1) * a + v[i].se * b;
                }else{
                    if(v[i].se <= p){
                        ans += calc0(v[i].se, 2);
                    }else{
                        ans += calc0(v[i].se, 1);
                    }
                }
            }else{
                ans += calc1(v[i].se);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
