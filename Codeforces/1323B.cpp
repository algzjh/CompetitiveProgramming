#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 4e4 + 5;
const int MOD = 998244353;
int a[MAXN], b[MAXN];
vector<int> row, col;
vector<int> sumrow, sumcol;

void init(){
    row.clear();
    col.clear();
    sumrow.clear();
    sumcol.clear();
}


int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    init();
    for(int i = 1; i <= n; ++i)  scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i)  scanf("%d", &b[i]);
    for(int i = 1; i <= n;){
        if(a[i] == 1){
            int p = i;
            while(p + 1 <= n and a[p + 1] == 1)  ++p;
            row.emplace_back(p - i + 1);
            i = p + 1;
        }else{
            ++i;
        }
    }
    sort(row.begin(), row.end());
    int prefix_sum = 0;
    for(auto i : row){
//        cout << i << " ";
        prefix_sum += i;
        sumrow.emplace_back(prefix_sum);
    }
//    cout << endl;
//
//    for(auto i : sumrow){
//        cout << i << " ";
//    }
//    cout << endl;



    for(int i = 1; i <= m;){
        if(b[i] == 1){
            int p = i;
            while(p + 1 <= m and b[p + 1] == 1)  ++p;
            col.emplace_back(p - i + 1);
            i = p + 1;
        }else{
            ++i;
        }
    }
    sort(col.begin(), col.end());
    prefix_sum = 0;
    for(auto i : col){
//        cout << i << " ";
        prefix_sum += i;
        sumcol.emplace_back(prefix_sum);
    }
//    cout << endl;
//
//    for(auto i : sumcol){
//        cout << i << " ";
//    }
//    cout << endl;

    LL ans = 0;
    int up = int(sqrt(k + 0.5));
    int p1, p2, sum1, sum2, cnt1, cnt2;
    for(int i = 1; i <= up; ++i){
        if(k%i == 0){
            p1 = lower_bound(row.begin(), row.end(), i) - row.begin();
            p2 = lower_bound(col.begin(), col.end(), k/i) - col.begin();
            if(p1 != row.size() and p2 != col.size()){
                sum1 = sumrow[sumrow.size() - 1];
                if(p1 != 0)  sum1 -= sumrow[p1 - 1];
                cnt1 = sum1 - (i - 1) * (row.size() - p1);


                sum2 = sumcol[sumcol.size() - 1];
                if(p2 != 0)  sum2 -= sumcol[p2 - 1];
                cnt2 = sum2 - (k/i - 1) * (col.size() - p2);

                ans += 1LL * cnt1 * cnt2;
            }

            if(i * i != k){
                p1 = lower_bound(row.begin(), row.end(), k/i) - row.begin();
                p2 = lower_bound(col.begin(), col.end(), i) - col.begin();
                if(p1 != row.size() and p2 != col.size()){
                    sum1 = sumrow[sumrow.size() - 1];
                    if(p1 != 0)  sum1 -= sumrow[p1 - 1];
                    cnt1 = sum1 - (k/i - 1) * (row.size() - p1);


                    sum2 = sumcol[sumcol.size() - 1];
                    if(p2 != 0)  sum2 -= sumcol[p2 - 1];
                    cnt2 = sum2 - (i - 1) * (col.size() - p2);

                    ans += 1LL * cnt1 * cnt2;
                }
            }

        }
    }
    printf("%lld\n", ans);
}

/*
50 50 6
1 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 0 1 1 1 0 1
1 1 0 1 0 1 1 0 1 1 1 1 1 1 0 1 1 0 1 0 0 1 1 1 1 0 0 1 0 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0

2153
 */
