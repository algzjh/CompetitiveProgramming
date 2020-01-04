#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
char s[25][15], t[25][15];
 
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%s", s[i]);
    }
    for(int i = 0; i < m; ++i){
        scanf("%s", t[i]);
    }
    int q, y;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &y);
        --y;
        printf("%s%s\n",s[y%n],t[y%m]);
    }
    return 0;
}
