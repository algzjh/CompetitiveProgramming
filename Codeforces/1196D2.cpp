#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MOD = 998244353;
char s[MAXN];
char alphabet[3] = {'R', 'G', 'B'};
int sum[MAXN];
 
 
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        int ans = k, tmp;
        for(register int i = 0; i < 3; ++i){
            int now = i;
            sum[0] = 0;
            for(register int j = 1; j <= n; ++j){
                sum[j] = sum[j - 1];
                if(s[j] != alphabet[now])  ++sum[j];
                now = now + 1;
                if(now == 3) now = 0;
                if(j >= k){
                    tmp = sum[j] - sum[j - k];
                    if(ans > tmp)  ans = tmp;
//                    ans = min(ans, sum[j] - sum[j - k]);
                }
            }
//            for(int r = k; r <= n; ++r){
//                ans = min(ans, sum[r] - sum[r - k]);
//            }
//            for(int kk = 1; kk <= n; ++kk){
//                cout << sum[kk] << " ";
//            }
//            cout << endl;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
3
5 2
BGGGG
5 3
RBRGR
5 5
BBBRR
 
 
RGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGB
BGGGG
 
GBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGB
BGGGG
 
BRGBRGBRGBRGBRGBRGBRGBRGBRGBRGBRGB
BGGGG
 
1 2 3
*/
