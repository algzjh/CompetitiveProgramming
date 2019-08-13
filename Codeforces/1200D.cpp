#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e3 + 5;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
char s[MAXN][MAXN];
int col[MAXN][MAXN], row[MAXN][MAXN];
int n, k;
int rans[MAXN][MAXN], cans[MAXN][MAXN];

void init(){
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    memset(rans, 0, sizeof(rans));
    memset(cans, 0, sizeof(cans));
}

int getRowAns(int x, int y){
    int ret = 0;
    for(int i = 1; i < x; ++i)  ret += (row[i][n] == n);
    for(int i = x; i <= x + k - 1; ++i){
        ret += (row[i][n] - row[i][y + k - 1] + row[i][y-1] == n-k);
    }
    for(int i = x + k; i <= n; ++i)  ret += (row[i][n] == n);
    return ret;
}

int getColAns(int x, int y){
    int ret = 0;
    for(int j = 1; j < y; ++j)  ret += (col[j][n] == n);
    for(int j = y; j <= y + k - 1; ++j){
        ret += (col[j][n] - col[j][x + k - 1] + col[j][x-1] == n - k);
    }
    for(int j = y + k; j <= n; ++j)  ret += (col[j][n] == n);
    return ret;
}

int checkRow(int x, int y){
    if(row[x][n] == n) return 0;
    return (row[x][n] - row[x][y + k - 1] + row[x][y-1] == n - k);
}

int checkCol(int x, int y){
    if(col[y][n] == n)  return 0;
    return (col[y][n] - col[y][x + k - 1] + col[y][x-1] == n - k);
}

void printArray(int arr[MAXN][MAXN]){
    for(int i = 1;i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    init();
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%s", s[i] + 1);
        for(int j = 1; j <= n; ++j){
            row[i][j] = row[i][j-1] + (s[i][j]=='W');
            col[j][i] = col[j][i-1] + (s[i][j]=='W');
        }
    }
//    cout << "row: " << endl;
//    printArray(row);
//    cout << "======" << endl;
//    cout << "col: " << endl;
//    printArray(col);
//    cout << "======" << endl;
    for(int j = 1; j <= n - k + 1; ++j){
        for(int i = 1; i <= n - k + 1; ++i){
            if(i == 1)  rans[i][j] = getRowAns(i, j);
            else rans[i][j] = rans[i-1][j] - checkRow(i-1, j) + checkRow(i + k - 1, j);
        }
    }
//    cout << "rans: " << endl;
//    printArray(rans);
//    cout << endl;
    int ans = 0;
    for(int i = 1; i <= n - k + 1; ++i){
        for(int j = 1; j <= n - k + 1; ++j){
            if(j == 1)  cans[i][j] = getColAns(i, j);
            else cans[i][j] = cans[i][j-1] - checkCol(i, j-1) + checkCol(i, j + k - 1);
            ans = max(ans, rans[i][j] + cans[i][j]);
        }
    }
//    cout << "cans: " << endl;
//    printArray(cans);
//    cout << endl;
    printf("%d\n", ans);
    return 0;
}
/*

*/
