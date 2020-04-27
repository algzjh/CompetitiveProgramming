#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e2 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
char t[MAXN], s[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s", t + 1);
        int n = strlen(t + 1);
        bool same = true;
        for(int i = 2; i <= n; ++i){
            if(t[i] != t[i-1]){
                same = false;
            }
        }
        if(same){
            printf("%s\n", t + 1);
            continue;
        }
        for(int i = 1; i <= n; ++i){
            printf("10");
        }
        printf("\n");
    }
    return 0;
}
