/*
 * Author: algzjh
 * Date: 15/8/20
 * Comment: math, 800
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;
const LL INF = 1e18;
const int MOD = 998244353;
int leafNum[MAXN];
LL nowSum;
vector<LL> vec[2];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int x, y, n;
        scanf("%d%d%d", &x, &y, &n);
        // k % x = y, k = c * x + y <= n, c = (n - y) / x
        printf("%d\n", (n - y)/x * x + y);
    }
    return 0;
}
/*

*/
