#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
int a[MAXN], b[MAXN], p[MAXN];
vector<PII> v;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        v.clear();
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        for(int i = 1; i <= m; ++i){
            scanf("%d", &p[i]);
        }
        sort(p + 1, p + m + 1);
        v.emplace_back(mk(p[1], p[1] + 1));
        int idx = 0;
        for(int i = 2; i <= m; ++i){
            PII pre = v[idx];
            if(pre.se == p[i]){
                v[idx].se = p[i] + 1;
            }else{
                v.emplace_back(mk(p[i], p[i] + 1));
                ++idx;
            }
        }
        for(int i = 0; i < v.size(); ++i){
//            cout << v[i].fi << " " << v[i].se << endl;
            sort(a + v[i].fi, a + v[i].se + 1);
        }
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            if(a[i] != b[i]){
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
 
/*
4 2
4 1 2 3
3 2
*/
