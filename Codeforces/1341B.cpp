#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[MAXN], b[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            b[i] = 0;
        }
        for(int i = 2; i <= n-1; ++i){
            if(a[i-1] < a[i] and a[i] > a[i+1]){
                b[i] = 1;
            }
        }
        for(int i = 2; i <= n; ++i){
            b[i] += b[i-1];
        }
        int ansl, p = 0;
        for(int l = 1; l <= n - k + 1; ++l){
            int r = l + k - 1;
            int tp = b[r - 1] - b[l] + 1;
            if(tp > p){
                p = tp;
                ansl = l;
            }
        }
        printf("%d %d\n", p, ansl);
    }
    return 0;
}
