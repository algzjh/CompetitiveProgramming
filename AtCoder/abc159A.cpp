# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const LL INF = 1e18;
typedef pair<double, int> PDI;



int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", n*(n-1)/2 + m*(m-1)/2);
    return 0;
}
