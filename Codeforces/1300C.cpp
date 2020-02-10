# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];
vector<int> s1[35], s0[35];
 
 
LL f(LL x, LL y){
    return (x|y) - y;
}
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        for(int j = 0; j <= 30; ++j){
            if((1<<j)&a[i]){
                s1[j].emplace_back(i);
            }else{
                s0[j].emplace_back(i);
            }
        }
    }
    int first = 0;
    for(int j = 30; j >= 0; --j){
        if(s1[j].size() == 1){
            first = s1[j][0];
            break;
            /*
            for(int k = j - 1; k >= 0; --k){
                if(s0[k].find(id) != s0[k].end()){
                    s0[k].erase(id);
                }
                if(s1[k].find(id) != s1[k].end()){
                    s1[k].erase(id);
                }
            }
             */
        }
    }
    if(first == 0)  first = 1;
    printf("%d", a[first]);
    for(int i = 1; i <= n; ++i){
        if(i != first)  printf(" %d", a[i]);
    }
    printf("\n");
    return 0;
}
/*
3
4
13 16 2 3 20 18 5 4
 */
