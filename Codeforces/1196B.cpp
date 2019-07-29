#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, char> PII;
const int MAXN = 2e5 + 5;
const int MOD = 998244353;
LL a[MAXN];
LL sum[MAXN];
vector<int> ans;
 
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        ans.clear();
        int n, k;
        scanf("%d%d", &n, &k);
        sum[0] = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        int now = 1;
        if(k & 1){
            if(sum[n] & 1){
                for(int i = 1; i <= n - 1; ++i){
                    if(ans.size() == k - 1) break;
                    if((sum[i] & 1) == now){
                        ans.emplace_back(i);
                        now ^= 1;
                    }
                }
                ans.emplace_back(n);
                if(ans.size() != k){
                    printf("NO\n");
                    continue;
                }
                printf("YES\n");
                for(int i = 0; i < ans.size(); ++i){
                    if(i != 0)  printf(" ");
                    printf("%d", ans[i]);
                }
                printf("\n");
            }else{
                printf("NO\n");
            }
        }else{
            if(sum[n] & 1){
                printf("NO\n");
            }else{
                for(int i = 1; i <= n - 1; ++i){
                    if(ans.size() == k - 1) break;
                    if((sum[i] & 1) == now){
                        ans.emplace_back(i);
                        now ^= 1;
                    }
                }
                ans.emplace_back(n);
                if(ans.size() != k){
                    printf("NO\n");
                    continue;
                }
                printf("YES\n");
                for(int i = 0; i < ans.size(); ++i){
                    if(i != 0)  printf(" ");
                    printf("%d", ans[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
/*
 
odd even odd
 
odd even odd even
*/
