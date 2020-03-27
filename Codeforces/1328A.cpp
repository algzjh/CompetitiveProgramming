# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 1e2 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const LL INF = 1e18;
typedef long long LL;
typedef pair<double, int> PDI;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        LL a, b;
        scanf("%lld%lld", &a, &b);
        if(a < b){
            printf("%lld\n", b - a);
        }else{
            if(a%b == 0)  printf("0\n");
            else  printf("%lld\n", b - a%b);
        }
    }
    return 0;
}
