# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
       int n;
       scanf("%d", &n);
       for(int i = 0; i < n; ++i){
           scanf("%d", &a[i]);
       }
       int prefixEnd = -1, suffixEnd = n;
       for(int i = 0; i < n; ++i){
           if(a[i] < i)  break;
           prefixEnd = i;
       }
       for(int i = n - 1; i >= prefixEnd; --i){
           if(a[i] < (n - 1 - i))  break;
           suffixEnd = i;
       }
       //cout << prefixEnd << " " << suffixEnd << endl;
       printf("%s\n", suffixEnd == prefixEnd ? "Yes" : "No");
    }
    return 0;
}
/*
4
0 1 1 0
2
0 0
 
2
0 1
 
3
1 0 1
 */
