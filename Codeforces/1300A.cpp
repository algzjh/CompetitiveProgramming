# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 100 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        int sum = 0, zero = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(a[i] == 0){
                ++zero;
            }
            sum += a[i];
        }
        if(zero == 0){
            printf("%d\n", sum == 0 ? 1 : 0);
        }else{
            printf("%d\n", sum + zero == 0 ? zero + 1 : zero);
        };
    }
    return 0;
}
