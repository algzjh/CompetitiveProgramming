 import java.io.*;
 import java.lang.reflect.Array;
 import java.util.*;


public class Main {
    private static int MOD = (int) (1e9 + 7);
    private static int MAXN = (int) (1e4 + 5);
    private static int[] dp = new int[10005];
    private static int n, w, h, ans;

    private static void init(){
        Arrays.fill(dp, 0);
        dp[0] = 1;
    }

    static int solve(){
        if(n == 0 || w == 1){
            return 0;
        }

        for(int i = 0; i < w; ++i){
            for(int j = n; j >= 0; --j){
                for(int k = 1; k <= h && j - k >= 0; ++k){
                    dp[j] = (int) ((1L * dp[j] + dp[j-k]) % MOD);
                }
            }
        }

        int ans = 0;
        for(int d : dp){
            ans = (int) ((1L * ans + d) % MOD);
        }

        for(int i = 0; i <= h; ++i){
            if(i * w <= n)  --ans;
            else break;
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            n = sc.nextInt();
            w = sc.nextInt();
            h = sc.nextInt();
            init();
            ans = solve();
            System.out.println(ans);
        }
    }
}
/*
25 5 5
15 5 5
10 10 1
4 2 2
*/