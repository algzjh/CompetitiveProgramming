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
char s1[55], s2[55];
vector<int> pos[55];
vector<int> ap[27];
bool used[55];
int n, m;
int cnt1[27], cnt2[27];

void init(int m){
    for(int i = 1; i <= m; ++i){
        pos[i].clear();
        used[i] = false;
    }
    for(int i = 0; i < 26; ++i){
        ap[i].clear();
    }
}

bool check(){
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    bool flag = true;
    for(int i = 1; i <= m; ++i){
        ++cnt1[s1[i]-'a'];
        ++cnt2[s2[i]-'a'];
    }
    for(int i = 0;i < 26; ++i){
        if(cnt1[i] != cnt2[i]){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%d%d", &n, &m);
        init(m);
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            scanf("%s%s", s1 + 1, s2 + 1);
            if(!check()) flag = false;
            if(!flag) continue;
            for(int j = 0; j < 26; ++j)  ap[j].clear();
            for(int j = 1; j <= m; ++j){
                ap[s2[j]-'a'].emplace_back(j);
            }

//            for(int j = 0; j < 26; ++j){
//                cout << char('a' + j) << ":" << endl;
//                for(auto it : ap[j]){
//                    cout << it << " ";
//                }
//                cout << endl;
//            }
            for(int j = 0; j < 26; ++j){
                sort(ap[j].begin(), ap[j].end());
            }
            for(int j = 1; j <= m; ++j){
                if(i == 1){
                    pos[j] = ap[s1[j]-'a'];
                }else{
                    sort(pos[j].begin(), pos[j].end());
                    auto it = set_intersection(pos[j].begin(), pos[j].end(),
                            ap[s1[j]-'a'].begin(), ap[s1[j]-'a'].end(), pos[j].begin());
                    pos[j].resize(it - pos[j].begin());
                }
                if(pos[j].size() == 0){
                    flag = false;
                }
            }
        }
        if(!flag){
            printf("-1\n");
            continue;
        }

//        for(int i = 1; i <= m; ++i){
//            for(auto it : pos[i]){
//                cout << it << " " ;
//            }
//            cout << endl;
//        }

        for(int i = 1; i <= m; ++i){
            if(i!=1)  printf(" ");
            int sz = pos[i].size();
            sort(pos[i].begin(), pos[i].end());
            for(int j = 0; j < sz; ++j){
                if(used[pos[i][j]]){
                    continue;
                }else{
                    printf("%d", pos[i][j]);
                    used[pos[i][j]] = true;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
/*
V M
*/