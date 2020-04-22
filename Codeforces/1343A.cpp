#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
int pow2[35];


void init(){
    pow2[1] = 2;
    for(int i = 2; i <= 30; ++i){
        pow2[i] = pow2[i-1] * 2;
    }
}

int main() {
    init();
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 2; i <= 30; ++i){
            if(n%(pow2[i]-1) == 0){
                printf("%d\n", n/(pow2[i]-1));
                break;
            }
        }
    }
    return 0;
}
/*
1 7 6 5
6 -1 -1
*/
