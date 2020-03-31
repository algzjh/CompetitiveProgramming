#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int a, b, c, ta, tb, tc;
        scanf("%d%d%d", &a, &b, &c);
        int ans = abs(a - b) + abs(a - c) + abs(b - c);
        for(int i = - 1; i <= 1; ++i){
            for(int j = -1; j <= 1; ++j){
                for(int k = -1; k <= 1; ++k){
                    ta = a + i, tb = b + j, tc = c + k;
                    ans = min(ans, abs(ta - tb) + abs(ta - tc) + abs(tb - tc));
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
