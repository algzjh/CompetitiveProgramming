#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int f[MAXN], in[MAXN], out[MAXN];
vector<int> v1, v2, v3;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &f[i]);
        if(f[i]){
            ++out[i];
            ++in[f[i]];
        }
    }
    v1.clear(), v2.clear(), v3.clear();
    for(int i = 1; i <= n; ++i){
        if(in[i] == 0 and out[i] == 0){
            v1.emplace_back(i);
        }else if(in[i] == 0 and out[i] == 1){
            v2.emplace_back(i);
        }else if(in[i] == 1 and out[i] == 0){
            v3.emplace_back(i);
        }
    }

//    for(auto it : v1){
//        cout << it << " ";
//    }
//    cout << endl;
//    for(auto it : v2){
//        cout << it << " ";
//    }
//    cout << endl;
//    for(auto it : v3){
//        cout << it << " ";
//    }
//    cout << endl;

    int sz = v1.size();
    if(sz == 1){
        f[v3[0]] = v1[0];
        v3[0] = v1[0];
    }else if(sz > 1){
        for(int i = 0; i < sz -1; ++i)  f[v1[i]] = v1[i+1];
        v2.emplace_back(v1[0]);
        v3.emplace_back(v1[sz-1]);
    }

    sz = v2.size();
    for(int i = 0; i < sz; ++i){
        f[v3[i]] = v2[i];
    }
    for(int i = 1; i <= n; ++i){
        if(i != 1)  printf(" ");
        printf("%d", f[i]);
    }
    printf("\n");
    return 0;
}
/*
*/
