#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(100 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, ans = 0;
        scanf("%d", &n);
        scanf("%s", s + 1);
        s[n + 1] = 'A';
        int p = n + 1;
        for(int i = n; i >= 1; --i){
            if(s[i] == 'A' && s[i+1] == 'A'){
                p = i;
            }else if(s[i] == 'A' && s[i+1] == 'P'){
                ans = max(ans, p - i - 1);
                p = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
