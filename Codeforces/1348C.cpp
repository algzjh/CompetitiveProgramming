#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
char s[MAXN];


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, k;
        scanf("%d%d%s", &n, &k, s);
        sort(s, s + n);
        if(k == 1){
            printf("%s\n", s);
            continue;
        }
        bool all_same1 = true, all_same2 = true;
        for(int i = 1; i < k; ++i){
            if(s[i] != s[i-1]){
                all_same1 = false;
                break;
            }
        }
        for(int i = k + 1; i < n; ++i){
            if(s[i] != s[i-1]){
                all_same2 = false;
                break;
            }
        }
        printf("%c", s[k - 1]);
        if(all_same1){
            if(all_same2){
                int max_i = (n - k) / k + ((n - k)%k > 0);
                for(int i = 0; i < max_i; ++i){
                    printf("%c", s[k]);
                }
            }else{
                for(int i = k; i < n; ++i){
                    printf("%c", s[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
/*
6
1 1
a
5 3
baacb
5 3
aaaaa
6 4
aaxxzz
 */
