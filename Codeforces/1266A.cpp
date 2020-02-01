# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 500 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN];

int main(){
    // 60 = 20 * 3, 20, 40, 60, 80, 00
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int even = 0, sum = 0, num;
        bool zero = false;
        for(int i = 1; i <= n; ++i){
            num = int(s[i] - '0');
            if(num == 0)  zero = true;
            if(not (num&1))  ++even;
            sum += num;
        }
        if(zero and even >= 2 and sum%3 == 0)  printf("red\n");
        else printf("cyan\n");
    }
    return 0;
}
/*
 */
