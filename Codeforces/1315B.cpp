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
typedef pair<LL, LL> PLL;
char s[MAXN];


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int money = 0, now = n;
        while(now > 1){
            int pos = now - 1;
            if(s[pos] == 'A')  money += a;
            else money += b;
            if(money > p)  break;
            while(pos - 1 >= 1 and s[pos - 1] == s[pos])  --pos;
            now = pos;
        }
        printf("%d\n", now);
    }
    return 0;
}
