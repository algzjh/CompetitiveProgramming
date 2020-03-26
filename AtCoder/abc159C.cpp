# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 1e2 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const LL INF = 1e18;
typedef long long LL;
typedef pair<double, int> PDI;


int main(){
    double L;
    scanf("%lf", &L);
    printf("%.8f\n", pow(L/3.0, 3));
    return 0;
}
/*
几何平均数 <= 算术平均数
pow(x1 * x2 * ... * xn, 1/n) <= (x1 + x2 + ... + xn) / n
 */
