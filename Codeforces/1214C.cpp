#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
char s[MAXN];
 
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int sum = 0;
    bool flag = true;
    for(int i = 1; i <= n; ++i){
        if(s[i] == '(')  ++sum;
        else --sum;
        if(sum < -1){
            flag = false;
            break;
        }
    }
    if(sum!=0) flag = false;
    printf("%s\n", flag?"Yes":"No");
    return 0;
}
