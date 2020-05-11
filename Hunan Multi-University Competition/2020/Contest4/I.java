import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = in.nextInt();
        int MAXN = (int) (2e3 + 5);
        int[] p = new int[MAXN];
        for(int i = 1; i <= n; ++i){
            p[i] = in.nextInt();
        }
        Arrays.sort(p, 1, n + 1);
        int sum = 0, ans = 1;
        for(int i = 1; i < n; ++i){
            sum += p[i];
            if(sum > p[n]){
                break;
            }
            ++ans;
        }
        System.out.println(ans);
    }
}
