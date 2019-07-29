#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MOD = 998244353;
 
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int b, w;
        scanf("%d%d", &b, &w);
        if(b <= w && (w - b) <= 2 * b + 1){// row
            printf("YES\n");
            for(int j = 1; j <= b * 2; ++j){
                printf("3 %d\n", j);
            }
            int remain = w - b;
            for(int j = 2; j <= 2 * b && remain > 0; j+=2){
                if(remain > 0){
                    printf("2 %d\n", j);
                    --remain;
                }
                if(remain > 0){
                    printf("4 %d\n", j);
                    --remain;
                }
            }
            if(remain > 0)  printf("3 %d\n", 2 * b + 1);
        }else if(b >= w && (b - w) <= 2 * w + 1){// column b > w
            printf("YES\n");
            for(int i = 1; i <= 2 * w; ++i){
                printf("%d 2\n", i);
            }
            int remain = b - w;
            for(int i = 2; i <= 2 * w && remain > 0; i+=2){
                if(remain > 0){
                    printf("%d 1\n", i);
                    --remain;
                }
                if(remain > 0){
                    printf("%d 3\n", i);
                    --remain;
                }
            }
            if(remain > 0)  printf("%d 2\n", 2 * w + 1);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
