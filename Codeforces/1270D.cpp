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
    int n, k;
    int tmp, x = -1, y = -1, cntx = 0, cnty = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k + 1; ++i){
        printf("?");
        for(int j = 1; j <= k + 1; ++j){
            if(i == j) continue;
            printf(" %d", j);
        }
        printf("\n");
        fflush(stdout);
        scanf("%*d %d",&tmp);
        if(x == -1) x = tmp;
        else if(x != tmp and y == -1) y = tmp;
        if(x == tmp) ++cntx;
        else ++cnty;
    }
//    cout << x << " " << cntx << " " << y << " " << cnty << endl;
    printf("! %d\n", x>y?cntx:cnty);
    fflush(stdout);
    return 0;
}
