#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 5;
const int MOD = 998244353;
char s[10];
 
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 2; i < n; ++i){
        if(n % i == 0){
            printf("%d%d\n", i, n/i);
            break;
        }
    }
    return 0;
}
