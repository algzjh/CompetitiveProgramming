# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 100 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b)  swap(a, b);
        int diff = a - b;
        int k = 1;
        while(diff < 0){
            diff += k;
            ++k;
        }
        if(not (diff&1)){
            printf("%d\n", k - 1);
        }else{
            diff += k;
            if(not (diff&1))  printf("%d\n", k);
            else  printf("%d\n", k + 1);
        }
    }
    return 0;
}
/*
Educational Codeforces Round 81
https://codeforces.com/blog/entry/72330?#comment-566093
*/
