#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const LL INF = 1e18;
char s[MAXN], t[MAXN];
int lm[MAXN], rm[MAXN];
 
void init(){
    memset(lm, 0, sizeof(lm));
    memset(rm, 0, sizeof(rm));
}
 
int main(){
    init();
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    int p = 1, q = 1;
    while(q <= m){
        while(s[p] != t[q])  ++p;
        lm[q] = p;
        ++q; ++p;
    }
    p = n, q = m;
    while(q >= 1){
        while(s[p] != t[q]) --p;
        rm[q] = p;
        --q; --p;
    }
//    for(int i = 1; i <= m; ++i){
//        cout << lm[i] << " ";
//    }
//    cout << endl;
//    for(int i = 1; i <= m; ++i){
//        cout << rm[i] << " ";
//    }
//    cout << endl;
    int ans = max(rm[1] - 1, n - lm[m]);
//    cout << "ans: " << ans << endl;
    for(int i = 1; i <= m - 1; ++i){
        ans = max(ans, rm[i + 1] - lm[i] - 1);
    }
    printf("%d\n", ans);
}
