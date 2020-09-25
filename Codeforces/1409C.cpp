#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e6+5;
typedef long long LL;

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        int dif = y - x;
        for(int d = 1; d <= dif; ++d){
            if(dif%d) continue;
            if(dif/d + 1 > n) continue;
            int k = min((y - 1)/d, n - 1);
            int a0 = y - k * d;
            for(int i = 0; i < n; ++i){
                printf("%d%c", a0 + i * d, i == n-1? '\n': ' ');
            }
            break;
        }
    }
    return 0;
}
/*

*/
