#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
char s[MAXN];
int p[MAXN], cnt[MAXN], ans[26];
 
 
void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
}
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        for(int i = 1; i <= m; ++i){
            scanf("%d", &p[i]);
            ++cnt[1];
            --cnt[p[i] + 1];
        }
        ++cnt[1];
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            sum += cnt[i];
            ans[s[i]-'a'] += sum;
        }
        for(int j = 0; j < 26; ++j){
            if(j != 0)  printf(" ");
            printf("%d", ans[j]);
        }
        printf("\n");
    }
    return 0;
}
 
/*
co
codeforc
cod
co
codeforce
codeforces
*/
