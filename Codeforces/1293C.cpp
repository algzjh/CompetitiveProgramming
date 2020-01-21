# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
bool a[3][MAXN];

int main(){
    int n, q, r, c;
    scanf("%d%d", &n, &q);
    memset(a, false, sizeof(a));
    int cnt = 0;
    for(int i = 1; i <= q; ++i){
        scanf("%d%d",&r, &c);
        for(int i = -1; i <= 1; ++i){
            if(1 <= c + i and c + i <= n and a[3 - r][c + i]){
                cnt += (a[r][c] ? -1 : 1);
            }
        }
        a[r][c] = (!a[r][c]);
        printf("%s\n", cnt > 0 ? "No" : "Yes");
    }
    return 0;
}
/*
(x,y)
(3-x, y-1), (3-x, y), (3-x, y+1)
*/
