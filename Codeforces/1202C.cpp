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
const int INF = 0x3f3f3f3f;
char s[MAXN];
int s1[MAXN], s2[MAXN];
 
// insert +1 to this prefix sum , return the minimum
int calcMinLen(int* presum, int n){
    int ma = -INF, lastmax, mi = INF, firstmin;
    for(int i = 1; i <= n; ++i){
//        cout << "i: " << i << " presum: " << presum[i] << endl;
        if(presum[i] >= ma){
            ma = presum[i];
            lastmax = i;
        }
        if(presum[i] < mi){
            mi = presum[i];
            firstmin = i;
        }
    }
    int ret = ma - mi + 1;
    if(lastmax < firstmin)  --ret;
    return ret;
}
 
void init(){
    s1[1] = s2[1] = 0;
}
 
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        init();
        scanf("%s", s+1);
        int n = strlen(s+1);
        int n1 = 1, n2 = 1;
        int miw = 0, maw = 0;
        int mih = 0, mah = 0;
        for(int i = 1;i <= n; ++i){
            if(s[i] == 'A' || s[i] == 'D'){
                ++n1;
                s1[n1] = s1[n1-1] + (s[i] == 'A' ? -1 : 1);
                miw = min(miw, s1[n1]);
                maw = max(maw, s1[n1]);
            }else{
                ++n2;
                s2[n2] = s2[n2-1] + (s[i] == 'S' ? -1 : 1);
                mih = min(mih, s2[n2]);
                mah = max(mah, s2[n2]);
            }
        }
        LL ans = 1LL * (maw - miw + 1) * (mah - mih + 1);
        if(n1 >= 3){
            int width = calcMinLen(s1, n1);
            ans = min(ans, 1LL * width * (mah - mih + 1));
            transform(s1 + 1, s1 + n1 + 1, s1 + 1, negate<int>());
            width = calcMinLen(s1, n1);
            ans = min(ans, 1LL * width * (mah - mih + 1));
        }
        if(n2 >= 3){
            int height = calcMinLen(s2, n2);
            ans = min(ans, 1LL * (maw - miw + 1) * height);
            transform(s2 + 1, s2 + n2 + 1, s2 + 1, negate<int>());
            height = calcMinLen(s2, n2);
            ans = min(ans, 1LL * (maw - miw + 1) * height);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
 
 
/*
WS
 
1
WW
*/
