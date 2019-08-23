#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 5e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int B = 707;
int a[MAXN], ans[710][710];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(op == 1){
            a[x] += y;
            for(int i = 1; i <= B; ++i)  ans[i][x%i] += y;
        }else{
            if(x <= B)  printf("%d\n", ans[x][y]);
            else{
                int ret = 0;
                for(int i = y; i <= 500000; i += x)  ret += a[i];
                printf("%d\n", ret);
            }
        }
    }
    return 0;
}
