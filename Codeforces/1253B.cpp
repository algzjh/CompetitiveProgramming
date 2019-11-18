#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MAXM = static_cast<const int>(1e6 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
enum employee {Home, In, Out};
int a[MAXN], sta[MAXM];
vector<int> ans, enter;

void init(){
    memset(sta, 0, sizeof(sta));
    ans.clear();
    enter.clear();
}

int main(){
    int n;
    scanf("%d", &n);
    init();
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    bool flag = true;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i] > 0){
            if(sta[a[i]] != Home)  {flag = false; break;}
            sta[a[i]] = In;
            enter.emplace_back(a[i]);
            ++cnt;
        }else{
            if(sta[-a[i]] != In)  {flag = false; break;}
            sta[-a[i]] = Out;
            --cnt;
        }
        if(cnt == 0){
            ans.emplace_back(2 * enter.size());
            for(auto p : enter) sta[p] = Home;
            enter.clear();
        }
    }
    if(cnt != 0)  flag = false;
    if(!flag){
        printf("-1\n");
    }else{
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
*/
