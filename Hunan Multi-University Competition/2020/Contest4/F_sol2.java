import java.util.*;


public class Main {
    final static int MAXN = (int) (2e5 + 5);
    static int[] f = new int[MAXN];
    static int[] pf = new int[MAXN];
    static int[] ma = new int [MAXN];

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

            int ans = 0, suf_ma = ma[n];
            for(int i = n - k; i >= 1; --i){
                ans = Math.max(ans, ma[i] + suf_ma);
                suf_ma = Math.max(suf_ma, ma[i + k - 1]);
            }
            System.out.println(ans);
        }
    }
}
