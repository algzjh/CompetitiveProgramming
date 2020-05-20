import java.io.*;
import java.util.*;


public class Main {
    private static int MAXN = (int) (1e3 + 5);
    private static String expr, ans;

    private static void init(){
        ans = "";
    }

    public static void main(String[] args) throws IOException {
//        File file = new File("data/alex.in");
        File file = new File("easy.in");
        BufferedWriter writer = new BufferedWriter(new FileWriter("easy.out"));
//        BufferedWriter writer = new BufferedWriter(new FileWriter("data/alex.out"));
        Scanner sc = new Scanner(file);

        init();
        expr = sc.nextLine();
        boolean flag = false;

        for(int i = 0; i < expr.length(); ++i){
            if(expr.charAt(i) == '+' || expr.charAt(i) == '-')  flag = false;
            if(flag)  ans += '+';
            if(expr.charAt(i) != '0')  flag = false;
            if(i > 0 && expr.charAt(i-1) == '-')  flag = true;
            ans += expr.charAt(i);
        }
        writer.write(ans);
        writer.close();
    }
}