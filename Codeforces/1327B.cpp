#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
typedef unsigned long long LL;
typedef pair<int, int> PII;
bool visg[MAXN], visk[MAXN];
 
 
void init(){
    memset(visg, false, sizeof(visg));
    memset(visk, false, sizeof(visk));
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        init();
        int n, k, x, cnt = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &k);
            for(int j = 1; j <= k; ++j){
                scanf("%d", &x);
                if(not visg[i] and not visk[x]){
                    visg[i] = true;
                    visk[x] = true;
                    ++cnt;
                }
            }
        }
        if(cnt == n){
            printf("OPTIMAL\n");
        }else{
            printf("IMPROVE\n");
            int ans1, ans2;
            for(int i = 1; i <= n; ++i){
                if(not visg[i]){
                    ans1 = i;
                    break;
                }
            }
            for(int i = 1; i <= n; ++i){
                if(not visk[i]){
                    ans2 = i;
                    break;
                }
            }
            printf("%d %d\n", ans1, ans2);
        }
    }
    return 0;
}
