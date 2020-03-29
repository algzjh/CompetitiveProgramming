#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
int a[MAXN];


bool cmp(int u, int v){
    return u > v;
}


int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= n; ++i){
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
/*
i < j
i - ai != j - aj
aj - ai != j - i
 */
