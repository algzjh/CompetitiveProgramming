#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const LL INF = 1e18;
int a[MAXN];
vector<int> ans;

int gcd(int a, int b){
    return b==0? a: gcd(b, a%b);
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        ans.clear();
        int V;
        scanf("%d", &V);
        int tV = V;
        int M = 0;
        while(V>0){
            M += V%10;
            V/=10;
        }
        V = tV;
//        cout << V <<  " " << M << endl;
        int g = gcd(V, M);
//        cout << "g: " << g << endl;
        if(g == 1){
            printf("1\n1\n");
            continue;
        }
        ans.emplace_back(1);
        ans.emplace_back(g);
        for(int i = 2; i * i <= g; ++i){
            if(g % i == 0){
                ans.emplace_back(i);
                if(i * i != g){
                    ans.emplace_back(g/i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        int sz = ans.size();
        printf("%d\n", sz);
        for(int i = 0; i < sz; ++i){
            if(i != 0)  printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
V M
*/