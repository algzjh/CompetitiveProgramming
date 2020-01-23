# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
 
 
int main(){
    int _, a, b, c, n;
    scanf("%d", &_);
    while(_--){
        scanf("%d%d%d%d", &a, &b, &c, &n);
        int n1 = (n + (a + b + c))/3 - a;
        int n2 = (a + n1 - b);
        int n3 = (a + n1 - c);
        if(n1 + n2 + n3 == n and 0 <= n1 and n1 <= n
        and 0 <= n2 and n2 <= n and 0 <= n3 and n3 <= n){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
/*
a + n1 = b + n2 = c + n3;
0 <= n1 <= n
0 <= a + n1 - b <= n
0 <= a + n1 - c <= n
n1 + n2 + n3 = n1 + a + n1 - b + a + n1 - c = 3 * n1 + 2 * a - b - c = n
3 * n1 + 3 * a - (a + b + c) = n
3 * (n1 + a) = n + (a + b + c)
n2 = a + n1 - b;
n3 = a + n1 - c;
 
*/
