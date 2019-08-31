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
const int INF = 0x3f3f3f3f;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        int mi = a[n], cnt = 0;
        for(int i = n - 1; i >= 1; --i){
            if(a[i] > mi){
                ++cnt;
            }else{
                mi = a[i];
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
