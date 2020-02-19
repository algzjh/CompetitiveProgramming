#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
char s[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        //op
        //used  usam
        //adinm
        if(s[n] == 'o')  printf("FILIPINO\n");
        else if(s[n] == 'u')  printf("JAPANESE\n");
        else printf("KOREAN\n");
    }
    return 0;
}
