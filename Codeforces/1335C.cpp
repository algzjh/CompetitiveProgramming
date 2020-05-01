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
int a[MAXN];
map<int, int> cnt;


void init(){
    cnt.clear();
}


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        init();
        int max_duplicate = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(cnt.find(a[i]) == cnt.end()){
                cnt[a[i]] = 1;
            }else{
                ++cnt[a[i]];
            }
            max_duplicate = max(max_duplicate, cnt[a[i]]);
        }
        if(n <= 2){
            printf("%d\n", n - 1);
        }else{
            int distinct_num = cnt.size();
            printf("%d\n", max(min(distinct_num - 1, max_duplicate),
                                      min(distinct_num, max_duplicate - 1)));
        }
    }
    return 0;
}
