# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s1[MAXN], s2[MAXN], mi[MAXN];
int mipos[MAXN]; // 'A' : 65


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s%s", s1 + 1, s2 + 1);
        int len1 = strlen(s1 + 1);
        mi[len1] = s1[len1];
        mipos[len1] = len1;
        for(int i = len1 - 1; i >= 1; --i){
            if(s1[i] < mi[i+1]){
                mi[i] = s1[i];
                mipos[i] = i;
            }else{
                mi[i] = mi[i+1];
                mipos[i] = mipos[i+1];
            }
        }
        for(int i = 1; i <= len1; ++i){
            if(s1[i] > mi[i]){
                swap(s1[i], s1[mipos[i]]);
                break;
            }
        }
        if(strcmp(s1 + 1, s2 + 1) < 0){
            printf("%s\n", s1 + 1);
        }else{
            printf("---\n");
        }
    }
    return 0;
}
/*
 */
