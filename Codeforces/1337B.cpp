#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int x, n, m;
        scanf("%d%d%d", &x, &n, &m);
        for(int i = 1; i <= n and x > 20; ++i){
            x = int(floor(x / 2.0)) + 10;
        }
        for(int i = 1; i <= m; ++i){
            x -= 10;
            if(x <= 0) break;
        }
        printf("%s\n", x <= 0? "YES": "NO");
    }
    return 0;
}
