#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        int dif = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(i > 1 and a[i] != -1 and a[i-1] != -1)  dif = max(dif, abs(a[i] - a[i-1]));
        }
        int mi = INF, ma = -INF;
        for(int i = 1; i <= n; ++i){
            if(a[i] == -1){
                if(i > 1 and a[i-1] != -1)  mi = min(a[i - 1], mi), ma = max(ma, a[i - 1]);
                if(i < n and a[i+1] != -1)  mi = min(a[i + 1], mi), ma = max(ma, a[i + 1]);
            }
        }
//        cout << mi << " " << ma << endl;
        int k = (mi + ma)/2;
        dif = max(dif, max(k - mi, ma - k));
        printf("%d %d\n", dif, k);
    }
    return 0;
}
