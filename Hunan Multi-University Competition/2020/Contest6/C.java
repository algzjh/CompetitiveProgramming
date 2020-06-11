 import java.io.*;
 import java.util.*;

 public class Main {
    private static final int MAXN = (int) (4e4 + 5);
    private static final int MOD = (int) (1e9 + 7);
    private static int n, k;
    private static long[][] dp = new long[MAXN][16];
    private static long[] selectCardsRes = new long[MAXN];
    private static Card[] cards = new Card[16];

    static class Card{
        long w, h, q;
        Card(long _w, long _h, long _q){
            w = _w;
            h = _h;
            q = _q;
        }
    }

    static void init(){
        for(int i = 1; i < (1<<n); ++i){
            long maxW = 0, maxH = 0;
            for(int j = 0; j < n; ++j){
                if((i & (1<<j)) != 0){
                    maxW = Math.max(maxW, cards[j].w);
                    maxH = Math.max(maxH, cards[j].h);
                }
            }
            long res = 0;
            for(int j = 0; j < n; ++j){
                if((i & (1<<j)) != 0){
                    res += (cards[j].q * (maxW * maxH - cards[j].w * cards[j].h));
                }
            }
            selectCardsRes[i] = dp[i][0] = res;
        }
    }

    static long solve(){
        init();
        for(int i = 1; i < k; ++i){
            for(int j = 1; j < (1<<n); ++j){
                dp[j][i] = dp[j][i-1];
                for(int k = j; k > 0; k = ((k - 1)&j)){
                    dp[j][i] = Math.min(dp[j][i], dp[k][i - 1] + selectCardsRes[k^j]);
                }
            }
        }
        return dp[(1<<n) - 1][k-1];
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            n = sc.nextInt();
            k = sc.nextInt();
            long w, h, q;
            for(int i = 0; i < n; ++i){
                w = sc.nextInt();
                h = sc.nextInt();
                q = sc.nextInt();
                cards[i] = new Card(w, h, q);
            }
            System.out.println(solve());
        }
    }
}
/*
5 1
10 10 5
9 8 10
4 12 20
12 4 8
2 3 16
*/