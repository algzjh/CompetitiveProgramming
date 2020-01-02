#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%d\n", n/k*k + min(k/2, n%k));
    }
    return 0;
}
