#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
LL a[MAXN];
LL sum;
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        sum = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        bool flag = true;
        LL max_so_far = a[1], curr_max = a[1];
        int L = 1;
        if(curr_max >= sum){
            printf("NO\n");
            continue;
        }
        for(int i = 2; i <= n; ++i){
            if(curr_max + a[i] <= a[i]){
                curr_max = a[i];
                L = i;
            }else{
                curr_max += a[i];
            }
            if(curr_max > sum){
                flag = false;
                break;
            }else if(curr_max == sum){
                if(not (L == 1 and i == n)){
                    flag = false;
                    break;
                }
            }
        }
        printf("%s\n", flag?"YES":"NO");
    }
    return 0;
}
