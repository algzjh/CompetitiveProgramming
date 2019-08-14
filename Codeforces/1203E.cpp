#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const LL INF = 1e18;
int a[MAXN];

struct Node{
    int L, R;
}p[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n;){
        int j = i + 1;
        while(j <= n && (a[j]==a[j-1] || a[j] == a[j-1] + 1)){
            ++j;
        }
        ++cnt;
        if(j - i == a[j-1] - a[i] + 1){
            p[cnt].L = a[i];
            p[cnt].R = a[j-1];
            if(cnt != 1 && p[cnt-1].R < p[cnt].L - 1){
                p[cnt].L -= 1;
                p[cnt].R -= 1;
            }
        }else if(j - i == a[j-1] - a[i] + 2){
            p[cnt].L = a[i];
            p[cnt].R = a[j-1];
            if(cnt == 1){
                if(p[cnt].L == 1)  p[cnt].R += 1;
                else  p[cnt].L -= 1;
            }else{
                if(p[cnt-1].R == p[cnt].L - 1)  p[cnt].R += 1;
                else  p[cnt].L -= 1;
            }
        }else{
            p[cnt].L = max(a[i]-1, 1);
            p[cnt].R = a[j-1] + 1;
        }
        i = j;
    }
    int ans = p[1].R - p[1].L + 1, rightmost = p[1].R;
    for(int i = 2; i <= cnt; ++i){
        if(p[i].L == rightmost)  --ans;
        ans += p[i].R - p[i].L + 1;
        rightmost = p[i].R;
    }
    printf("%d\n", ans);
    return 0;
}
/*

*/
