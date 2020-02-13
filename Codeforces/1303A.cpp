#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN];
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int L = 1;
        while(L <= n and s[L] == '0')  ++L;
        int R = n;
        while(R >= 1 and s[R] == '0')  --R;
        int ans = 0;
        if(L < R){
            for(int i = L; i <= R; ++i){
                if(s[i] == '0')  ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
