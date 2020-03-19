# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e2 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<double, int> PDI;
int a[MAXN];


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        int odd1 = -1, odd2 = -1, even = -1;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(a[i]&1){
                if(odd1 == -1)  odd1 = i;
                else if(odd2 == -1)  odd2 = i;
            }else  even = i;
        }
        if(odd1 != -1 and odd2 != -1){
            printf("2\n%d %d\n", odd1, odd2);
        }else if(even != -1){
            printf("1\n%d\n", even);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
