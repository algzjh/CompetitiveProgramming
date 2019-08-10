#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
char s1[MAXN], s2[MAXN];
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s%s", s1 + 1, s2 + 1);
        int n1 = strlen(s1 + 1), n2 = strlen(s2 + 1);
        reverse(s1 + 1, s1 + n1 + 1);
        reverse(s2 + 1, s2 + n2 + 1);
        int p1, p2;
        for(int i = 1; i <= n1; ++i){
            if(s1[i] == '1'){
                p1 = i;
                break;
            }
        }
        for(int i = 1; i <= n2; ++i){
            if(s2[i] == '1'){
                p2 = i;
                break;
            }
        }
        for(int i = p1; i <= n1; ++i){
            if(s1[i] == '1'){
                if(i >= p2){
                    printf("%d\n", i-p2);
                    break;
                }
            }
        }
    }
    return 0;
}
/*
10
34 24 21 42 80 2 4 200 32 1
 
5
2 3 1 100 100
*/
