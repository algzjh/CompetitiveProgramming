#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int n, a[MAXN];
 
int main(){
    scanf("%d", &n);
    if(n & 1){
        int p = 1, q = n + 1;
        int cnt = 0;
        for(int i = 1; i <= 2 * n; i += 2){
            ++cnt;
            if(cnt & 1){
                a[p] = i;
                a[q] = i + 1;
            }else{
                a[q] = i;
                a[p] = i + 1;
            }
            ++p;++q;
        }
        printf("YES\n");
        for(int i = 1; i <= 2 * n; ++i){
            if(i != 1)  printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
