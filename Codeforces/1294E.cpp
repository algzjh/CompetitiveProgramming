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
int a[MAXN], cnt[MAXN];


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &a[i * m + j]);
            --a[i * m + j];
        }
    }
    int ans = 0, tmp;
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i){
            cnt[i] = 0;
        }
        for(int i = 0; i < n; ++i){
            if(a[i * m + j] % m == j and a[i * m + j] / m < n){
                ++cnt[(i - a[i * m + j] / m + n)%n];
            }
        }
        tmp = INF;
        for(int i = 0; i < n; ++i){
            tmp = min(tmp, n - cnt[i] + i);
        }
        ans += tmp;
    }
    printf("%d\n", ans);
    return 0;
}
/*
0 1 2
3 4 5
6 7 8

(i,j): i * m + j


j
m+j
2*m + j
(n-1)*m + j

min_{i=0}^{n-1} n - cnt_i + i

if a_{i,j} % m != j
pos = floor(a_{i,j}/m) < n
 cyclic shift (i - pos + n) % n
*/
