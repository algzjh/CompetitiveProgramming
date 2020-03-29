#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e2 + 5;
LL ans1, ans2;
 
bool check(LL l, LL r, LL v){
    return l <= v and v <= r;
}
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        LL n, x, y;
        scanf("%lld%lld%lld", &n, &x, &y);
        LL lx, rx, ly, ry;
        lx = max(1LL, x + y + 1 - n), rx = n;
        ly = max(1LL, x + y - n + 1), ry = n;
//        cout << lx << " " << rx << endl;
//        cout << ly << " " << ry << endl;
        ans1 = rx - lx;
        if(not check(lx, rx, x) and not check(ly, ry, y))  ans1 += 1;
        lx = 1, rx = min(x + y - 1, n);
        ly = 1, ry = min(x + y - 1, n);
        ans2 = rx - lx;
        if(not check(lx, rx, x) and not check(ly, ry, y))  ans2 += 1;
        printf("%lld %lld\n", n - ans1, ans2 + 1);
    }
    return 0;
}
