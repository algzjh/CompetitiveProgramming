#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        bool flag = false;
        int L, R;
        int mi = INF, pos = -1;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(flag) continue;
            if(mi >= a[i] - i){
                mi = a[i] - i;
                pos = i;
            }
            if(a[i] - i > mi){
                flag = true;
                L = pos, R = i;
            }
        }
        if(!flag){
            mi = INF, pos = -1;
            for(int i = n; i >= 1; --i){
                if(mi >= a[i] + i){
                    mi = a[i] + i;
                    pos = i;
                }
                if(a[i] + i > mi){
                    flag = true;
                    L = i, R = pos;
                    break;
                }
            }
        }
        if(flag){
            printf("YES\n");
            printf("%d %d\n", L, R);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
/*
3
4
2 0 1 9
 
 
100
2
1 1
2
1 2
3
1 2 2
3
1 2 1
3
1 2 3
3
1 3 2
3
1 1 1
 
 
100
1
1
NO
2
1 1
NO
2
1 2
NO
3
1 2 2
NO
3
1 2 1
NO
3
1 2 3
NO
3
1 3 2
YES
1 2
3
1 1 1
YES
1 2
NO
 
 
*/
