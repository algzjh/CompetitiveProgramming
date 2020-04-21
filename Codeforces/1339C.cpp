#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN];
 
 
int countBits(int x){
    int cnt = 0;
    while(x){
        ++cnt;
        x >>= 1;
    }
    return cnt;
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
        // nondecreasing
        b[1] = a[1];
        int diff = 0;
        for(int i = 2; i <= n; ++i){
            if(a[i] >= b[i-1])  b[i] = a[i];
            else  b[i] = b[i-1];
            diff = max(diff, b[i] - a[i]);
        }
        printf("%d\n", countBits(diff));
    }
    return 0;
}
/*
1 7 6 5
6 -1 -1
*/
