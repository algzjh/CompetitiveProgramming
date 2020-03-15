#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
char s[MAXN];
vector<PII> v;
 
void init(){
    v.clear();
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        init();
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        v.emplace_back(mk(0, 0));
        for(int i = 1; i <= n; ++i){
            if(s[i] == 'R'){
                int L = i, R = i;
                while(R + 1 <= n and s[R + 1] == 'R')  ++R;
                v.emplace_back(mk(L, R));
                i = R;
            }
        }
        v.emplace_back(mk(n + 1, n + 1));
        int sz = v.size(), ans = 0;
        for(int i = 0; i < sz - 1; ++i){
            ans = max(ans, v[i + 1].fi - v[i].se);
        }
        printf("%d\n", ans);
    }
    return 0;
}
