#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 2e3 + 5;
const int INF = 0x3f3f3f3f;
int a[MAXN], b[MAXN * 2];
int c[MAXN], d[MAXN * 2];
 
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
    }
    if(n == 1){
        printf("%d\n", (b[1] - a[1] + m)%m);
        return 0;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for(int i = n + 1; i <= 2 * n; ++i){
        b[i] = b[i-n] + m;
    }
    for(int i = 1; i < n; ++i){
        c[i] = a[i+1] - a[i];
    }
    for(int i = 1; i < 2 * n; ++i){
        d[i] = b[i+1] - b[i];
    }
    bool flag;
    int ans = INF;
    for(int i = 1; i <= n + 1; ++i){
        flag = true;
        for(int j = 1; j < n; ++j){
            if(c[j] != d[i + j - 1]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans = min(ans, (b[i] - a[1] + m)%m);
        }
    }
    printf("%d\n", ans);
    return 0;
}
