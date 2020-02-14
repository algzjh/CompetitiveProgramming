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
char a[MAXN], b[MAXN], c[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s%s%s", a + 1, b + 1, c + 1);
        int n = strlen(a + 1);
        bool flag = true;
        // ai bi ci
        // ci bi ai
        // ai ci bi
        for(int i = 1; i <= n; ++i){
            if(not (c[i] == b[i] or a[i] == c[i])){
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
