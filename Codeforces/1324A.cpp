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
int a[MAXN];


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        int ma = -INF;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            ma = max(ma, a[i]);
        }
        for(int i = 1; i <= n; ++i){
            if(a[i] < ma){
                a[i] += 2 * ((ma - a[i] + 1) / 2);
            }
        }
        bool flag = true;
        for(int i = 2; i <= n; ++i){
            if(a[i] != a[1]){
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
