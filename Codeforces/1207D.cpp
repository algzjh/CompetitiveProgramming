#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 3e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int A[MAXN];
 
struct Node{
    int x, y;
}a[MAXN];
 
void init(int n){
    A[0] = 1;
    for(int i = 1; i <= n; ++i){
        A[i] = 1LL * A[i-1] * i % MOD;
    }
}
 
bool cmp1(const Node &u, const Node &v){
    return u.x < v.x;
}
 
bool cmp2(const Node &u, const Node &v){
    return u.y < v.y;
}
 
bool cmp3(const Node &u, const Node &v){
    if(u.x == v.x)  return u.y < v.y;
    return u.x < v.x;
}
 
int main(){
    int n;
    scanf("%d", &n);
    init(n);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &a[i].x, &a[i].y);
    }
 
    if(n == 1){
        printf("0\n");
        return 0;
    }
 
    int ans = A[n];
 
//    cout << "ans: " << ans << endl;
 
    int tmp = 1;
    sort(a + 1, a + n + 1, cmp1);
    for(int i = 1; i <= n; ){
        int j = i + 1;
        while(j <= n and a[j].x == a[j-1].x) ++j;
        if(j - i >= 2){
            tmp = (1LL * tmp * A[j-i])  % MOD;
        }
        i = j;
    }
 
//    cout << "tmp: " << tmp << endl;
 
    ans = (ans - tmp + MOD) % MOD;
 
//    cout << "ans: " << ans << endl;
 
    tmp = 1;
    sort(a + 1, a + n + 1, cmp2);
    for(int i = 1; i <= n; ){
        int j = i + 1;
        while(j <= n and a[j].y == a[j-1].y) ++j;
        if(j - i >= 2){
            tmp = (1LL * tmp * A[j-i])  % MOD;
        }
        i = j;
    }
//    cout << "tmp: " << tmp << endl;
 
    ans = (ans - tmp + MOD) % MOD;
 
//    cout << "ans: " << ans << endl;
 
    sort(a + 1, a + n + 1, cmp3);
    bool flag = true;
    for(int i = 2; i <= n; ++i){
        if(a[i].x >= a[i-1].x && a[i].y >= a[i-1].y) continue;
        else {flag = false;  break; }
    }
 
//    cout << "flag: " << flag << endl;
 
    if(flag){
        tmp = 1;
        for(int i = 1; i <= n;){
            int j = i + 1;
            while(j <= n && a[j].x == a[j-1].x && a[j].y == a[j-1].y) ++j;
            if(j - i >= 2){
                tmp = (1LL * tmp * A[j - i]) % MOD;
            }
            i = j;
        }
//        cout << "tmp: " << tmp << endl;
 
        ans = (1LL * ans + tmp) % MOD;
 
//        cout << "ans: " << ans << endl;
    }
    printf("%d\n", ans);
    return 0;
}
