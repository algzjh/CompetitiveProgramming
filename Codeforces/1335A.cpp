#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        if(n&1)  printf("%d\n", n - ((n + 1) / 2));
        else printf("%d\n", n - n/2  - 1);
    }
    return 0;
}
