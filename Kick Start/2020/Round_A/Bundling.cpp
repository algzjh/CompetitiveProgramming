#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e6 + 5;
const int INF = 0x3f3f3f3f;
typedef unsigned long long LL;
typedef pair<int, int> PII;
int n, k;
int ch[MAXN][26], cnt[MAXN], fa[MAXN], dep[MAXN], sz;
char s[MAXN];

int newNode(){
    ++sz;
    memset(ch[sz], 0, sizeof(ch[sz]));
//    fill(ch[sz], ch[sz] + 26, 0);
    cnt[sz] = fa[sz] = dep[sz] = 0;
    return sz;
}

void init(){
    sz = 0;
    newNode();
}

int main(){
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        init();
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i){
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            int p = 1, id;
            for(int j = 1; j <= len; ++j){
                id = int(s[j] - 'A');
                if(ch[p][id] == 0){
                    ch[p][id] = newNode();
                    fa[ch[p][id]] = p;
                    dep[ch[p][id]] = dep[p] + 1;
                }
                p = ch[p][id];
            }
            cnt[p] += 1;
        }
        int ans = 0;
        for(int i = sz; i >= 1; --i){
            ans += cnt[i] / k * dep[i];
            cnt[fa[i]] += cnt[i] % k;
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
