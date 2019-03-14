/*
 * CSU1770
 * prefixsum
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n, t;
int a[MAXN], b[MAXN];

void init(){
    memset(b, 0, sizeof(b));
}

int main(){
    while(~scanf("%d%d", &n, &t)){
        init();
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        int L, R;
        for(int i = 1; i <= t; ++i){
            scanf("%d%d", &L, &R);
            ++b[L], --b[R + 1];
        }
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            if(i != 1) printf(" ");
            sum += b[i];
            printf("%d", (sum&1)?1-a[i]:a[i]);
        }
        printf("\n");
    }
    return 0;
}
/*

*/
