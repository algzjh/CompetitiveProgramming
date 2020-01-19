#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e5 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n, m, C[1025][25];

void init(){
    C[1][0] = C[1][1] = 1;
    for(int i = 2; i <= n + 2*m - 1; ++i){
        C[i][0] = 1;
        for(int j = 1; j <= min(i, 20); ++j){
            C[i][j] = (1LL * C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    printf("%d\n", C[n+2*m-1][2*m]);
    return 0;
}
/*
隔板法
*/
