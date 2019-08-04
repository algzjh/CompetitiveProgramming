#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 5;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int a[MAXN], b[MAXN];
int n, k, sum;

bool check(int g){
    for(int i = 1;i <= n; ++i){
        b[i] = a[i] % g;
    }
    sort(b + 1, b + n + 1);
    int L = 1, R = n, cnt = 0;
    while(L<R){
        if(b[L] + b[R] >g){
            cnt+=(g-b[R]);
            b[L] -= (g-b[R]);
            b[R] = g;
            --R;
        }else if(b[L] + b[R] == g){
            cnt += b[L];
            b[R] = g;
            --R;
            b[L] = 0;
            ++L;
        }else{
            cnt += b[L];
            b[R] += b[L];
            b[L] = 0;
            ++L;
        }
    }
    if(L==R && (b[L]%g!=0))  return false;
    return cnt <= k;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1;i <= n;++i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int up = int(sqrt(sum));
    int ans = 0;
    for(int i = up; i >= 1; --i){
        if(sum%i == 0){
            //cout << "i: " << i << " sum/i: " << sum/i << endl;
            if(check(i))  ans = max(ans, i);
            if(check(sum/i)) ans = max(ans, sum/i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*

*/
