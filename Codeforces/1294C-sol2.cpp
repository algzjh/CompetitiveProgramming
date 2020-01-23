# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a, b, c;
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, tn;
        scanf("%d", &n);
        tn = n;
        a = -1, b = -1, c = -1;
        for(int i = 2; i * i < n; ++i){
            if(n % i == 0){
                a = i;
                n /= i;
                break;
            }
        }
        for(int i = 2; i * i < n; ++i){
            if(n % i == 0 and i != a){
                b = i;
                n /= i;
                c = n;
                break;
            }
        }
        if(2 <= a and 2 <= b and 2 <= c){
            printf("YES\n");
            printf("%d %d %d\n", a, b, c);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
