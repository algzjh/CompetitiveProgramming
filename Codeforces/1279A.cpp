#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e3 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[4];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        for(int i = 1; i <= 3; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 3 + 1);
        printf("%s\n", a[3] - a[2] - a[1] > 1 ? "No" : "Yes");
    }
    return 0;
}
