#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
char a[MAXN], b[MAXN];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", a + 1);
    printf("%d\n", n);
    strcpy(b + 1, a + 1);
    for(int i = k + 1; i <= n; ++i){
        b[i] = b[i-k];
    }
    if(strcmp(b + 1, a + 1) < 0){
        for(int i = k; i >= 1; --i){
            if(b[i] == '9')  b[i] = '0';
            else{
                ++b[i];
                break;
            }
        }
        for(int i = k + 1; i <= n; ++i){
            b[i] = b[i-k];
        }
    }
    printf("%s\n", b + 1);
    return 0;
}
