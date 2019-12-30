#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e2 + 5;
const int INF = 0x3f3f3f3f;
int a[MAXN], b[MAXN];
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, k1, k2;
        scanf("%d%d%d", &n, &k1, &k2);
        int m1 = -1, m2 = -1;
        for(int i = 1; i <= k1; ++i){
            scanf("%d", &a[i]);
            m1 = max(m1, a[i]);
        }
        for(int i = 1; i <= k2; ++i){
            scanf("%d", &b[i]);
            m2 = max(m2, b[i]);
        }
//        cout << m1 << " " << m2 << endl;
        if(m1 > m2)  printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
 
*/
