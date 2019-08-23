#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 3e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
 
int main(){
    fflush(stdout);
    string s = "11111110000000";
    bitset<14> b1 (s);
    int a = b1.to_ulong();
    printf("?");
    for(int i = 1; i <= 100; ++i){
        printf(" %d", a + i);
    }
    printf("\n");
    fflush(stdout);
    int y;
    scanf("%d", &y);
    int ans = (y ^ a) & a;
    s = "00000001111111";
    bitset<14> b2 (s);
    a = b2.to_ulong();
//    cout << a << endl;
    printf("?");
    for(int i = 1; i <= 100; ++i){
        printf(" %d", (i << 7) + a);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d", &y);
    ans = ans + ((y ^ a) & a);
    printf("! %d\n", ans);
    fflush(stdout);
    return 0;
}
