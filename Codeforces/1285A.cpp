#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN];
 
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int L = 0, R = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i] == 'L')  ++L;
        else ++R;
    }
    printf("%d\n", R + L + 1);
    return 0;
}
/*
3 4 6 7
 */
