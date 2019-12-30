#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
LL a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        LL sum = 0, xorsum = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i]);
            sum += a[i];
            if(i != 1)  xorsum ^= a[i];
            else xorsum = a[i];
        }
        printf("2\n");
        printf("%lld %lld\n",xorsum, sum + xorsum);
    }
    return 0;
}
