#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
char s[MAXN], ans[MAXN];


int main() {
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        scanf("%s", s + 1);
        int left = s[1] - '0';
        int pos = 1;
        for(int i = 1; i <= left; ++i){
            ans[pos] = '(';
            ++pos;
        }
        ans[pos] = s[1];
        ++pos;
        int n = strlen(s + 1);
        for(int i = 2; i <= n; ++i){
            int dif = s[i] - s[i - 1];
            if(dif > 0){
                for(int j = 1; j <= dif; ++j){
                    ans[pos] = '(';
                    ++pos;
                    ++left;
                }
            }else if(dif < 0){
                for(int j = 1; j <= -dif; ++j){
                    ans[pos] = ')';
                    ++pos;
                    --left;
                }
            }
            ans[pos] = s[i];
            ++pos;
        }
        if(left > 0){
            for(int i = 1; i <= left; ++i){
                ans[pos] = ')';
                ++pos;
            }
        }
        ans[pos] = '\0';
        printf("Case #%d: %s\n", cas++, ans + 1);
    }
}
/*
4
221
 */
