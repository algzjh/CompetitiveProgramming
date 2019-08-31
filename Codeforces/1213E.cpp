#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
char s[10], t[10], p[10], tp[10];
 
int main(){
    int n;
    scanf("%d%s%s", &n, s, t);
    p[0] = 'a', p[1] = 'b', p[2] = 'c', p[3] = '\0';
    int flag = 0;
    do{
        for(int i = 0; i < 6; ++i){
            tp[i] = p[i/2];
        }
        tp[6] = '\0';
        if(strstr(tp, s) == nullptr && strstr(tp, t) == nullptr){
            flag = 1;
            break;
        }
        strcpy(tp, "");
        strcat(tp, p);
        if(n > 1) strcat(tp, p);
        if(strstr(tp, s) == nullptr && strstr(tp, t) == nullptr){
            flag = 2;
            break;
        }
    }while(next_permutation(p, p + 3));
    if(flag == 0){
        printf("NO\n");
    }else if(flag == 1){
        printf("YES\n");
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < n; ++j){
                printf("%c", p[i]);
            }
        }
        printf("\n");
    }else{
        printf("YES\n");
        for(int i = 1; i <= n; ++i){
            printf("%s", p);
        }
        printf("\n");
    }
    return 0;
}
