#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 5;
const int MOD = 998244353;
int b[10];
 
int main() {
    int n;
    scanf("%d", &n);
    int p = 0;
    for(int i = 0; i <= n; ++i){
        if(n & (1<<i))  b[i] = 1;
        else b[i] = 0;
    }
    swap(b[0], b[4]);
    swap(b[2], b[3]);
    int ans = 0;
    for(int i = 0; i < 6; ++i){
        ans += b[i] * (1<<i);
    }
    printf("%d\n", ans);
    return 0;
}
/*
And they lived happily ever after
5     0     2     3      1    4
 
And after happily lived ever they
5     4      3      2     1    0
*/
