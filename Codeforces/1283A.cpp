#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int h, m;
        scanf("%d%d", &h, &m);
        printf("%d\n",24*60-h*60-m);
    }
    return 0;
