#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
 
int main(){
   int _;
   scanf("%d", &_);
   while(_--){
       int a, b, c;
       scanf("%d%d%d", &a, &b, &c);
       if(a + c <= b){
           printf("0\n");
       }else{
           if(c == 0)  printf("1\n");
           else{
               int L = max(int(ceil((b + c - a + 1)/2.0)), 0);
//               cout << "L: " << L << endl;
               if(L > c)  printf("0\n");
               else printf("%d\n", c - L + 1);
           }
       }
   }
}
