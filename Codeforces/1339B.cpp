#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
int a[MAXN];
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int L, R;
        if(n&1){
            L = (n+1)/2, R = (n+1)/2;
            printf("%d", a[R]);
        }else{
            L = n/2, R = n/2 + 1;
            printf("%d %d", a[R], a[L]);
        }
        ++R;
        --L;
        while(R <= n and L >= 1){
            printf(" %d %d", a[R], a[L]);
            ++R;
            --L;
        }
        printf("\n");
    }
    return 0;
}
