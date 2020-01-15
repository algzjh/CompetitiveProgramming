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
    int _, a, b, c, r, intersect;
    scanf("%d", &_);
    while(_--){
        scanf("%d%d%d%d", &a, &b, &c, &r);
        if(a > b) swap(a, b);
        if(c+r < a || c-r > b){
            intersect = 0;
        }else{
            intersect = min(b, c + r) - max(a, c - r);
        }
        printf("%d\n", b - a  - intersect);
    }
    return 0;
}
