#include <iostream>
using namespace std;
const int MAXN = 1e5 + 5;
int s[MAXN], sum[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &s[i]);
        sum[i] = sum[i - 1] + s[i];
    }
    int q, l, r;
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &l, &r);
        printf("%d\n", (sum[r] - sum[l-1])/10 );
    }

}