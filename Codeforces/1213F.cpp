#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int p[MAXN], q[MAXN], rq[MAXN], rp[MAXN];
char s[MAXN];
 
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &p[i]);
        rp[p[i]] = i;
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", &q[i]);
        rq[q[i]] = i;
    }
    char c = 'a' - 1;
    int last = 0;
    for(int i = 1; i <= n; ++i){
        if(i > last){
            if(c < ('a' + k - 1))  ++c;
            for(int j = last + 1; j <= rq[p[i]]; ++j)  s[j] = c;
            last = rq[p[i]];
        }else if(rq[p[i]] > last){
            for(int j = last + 1; j <= rq[p[i]]; ++j)  s[j] = c;
            last = rq[p[i]];
        }
    }
    if(c != 'a' + k - 1){
        printf("NO\n");
    }else{
        printf("YES\n");
        for(int i = 1; i <= n; ++i){
            printf("%c", s[rp[i]]);
        }
        printf("\n");
    }
    return 0;
}
/*
5 4
1 3 2 4 5
2 3 5 1 4
*/
