#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, char> PII;
const int MAXN = 3e5 + 5;
const int MOD = 998244353;
LL a[4];
 
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);
        sort(a + 1, a + 3 + 1);
        LL sum = a[1] + a[2] + a[3];
        printf("%lld\n", sum/2);
    }
    return 0;
}
/*
 
Max
a_L + ... a_R - k * ceil(r - l + 1 / m)
 
a_L + ... a_K + a_{K + 1} + ... + a_R  - k * ceil ( r - k + k - l + 1 / m)
 
r - k + k + 1 - l
 
*/
