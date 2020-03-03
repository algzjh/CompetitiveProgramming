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
            int p = now - 1;
            while(p - 1 >= 1 and s[p - 1] == s[p])  --p;
            if(s[p] == 'A')  money += a;
            else money += b;
            if(money > p){
                break;
            }
            now = p;
        }
        printf("%d\n", now);
    }
    return 0;
}
