import java.util.*;


public class Main {
    final static int MAXN = (int) (2e5 + 5);
    static int[] f = new int[MAXN];
    static int[] pf = new int[MAXN];
    static int[] ma = new int [MAXN];
    static int[][] st = new int[MAXN][20];

    private static int log(int x, int b){
        return (int)(Math.log(x) / Math.log(b) + 1e-10);
    }

    private static void ST_prework(int n){
        for(int i = 1; i <= n; ++i)  st[i][0] = ma[i];
        int t = log(n, 2) + 1;
        for(int j = 1; j < t; ++j){
            for(int i = 1; i <= n - (1<<j) + 1; ++i){
                st[i][j] = Math.max(st[i][j-1], st[i + (1<<(j-1))][j-1]);
            }
        }
    }

    private static int ST_query(int l, int r){
        int k = log(r - l + 1, 2);
        return Math.max(st[l][k], st[r - (1<<k) + 1][k]);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        pf[0] = 0;
        for(int i = 1; i <= n; ++i){
           f[i] = sc.nextInt();
           pf[i] = pf[i-1] + f[i];
        }
        if(2 * k >= n){
            System.out.println(pf[n]);
        }else{
            for(int i = 1; i <= n; ++i){
                if(i < k)  ma[i] = pf[i];
                else{
                    ma[i] = pf[i] - pf[i-k];
                }
            }
            ST_prework(n);
            int ans = 0;
            for(int i = 1; i <= n - k; ++i){
                ans = Math.max(ans, ma[i] + ST_query(i + k, n));
            }
            System.out.println(ans);
        }
    }
}
