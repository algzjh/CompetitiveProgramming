import java.io.*;
import java.util.*;


public class Main {
    private static int MAXN = (int) (1e3 + 5);
    private static String expr, ans;

    private static void init(){
        ans = "";
    }

    public static void main(String[] args) throws IOException {
        File file = new File("data/alex.in");
//        File file = new File("easy.in");
//        BufferedWriter writer = new BufferedWriter(new FileWriter("easy.out"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("data/alex.out"));
        Scanner sc = new Scanner(file);

        init();
        expr = sc.nextLine();
        boolean flag = false, jump = false;

        for(int i = 0; i < expr.length(); ++i){
            ans += expr.charAt(i);
            if(expr.charAt(i) == '-'){
                flag = true;
            }else if(expr.charAt(i) == '+'){
                flag = false;
            }else if(flag){
                if(i + 1 < expr.length()){
                    if(expr.charAt(i + 1) == '+' || expr.charAt(i + 1) == '-'){
                        flag = false;
                    }else if(expr.charAt(i + 1) == '0'){
                        while(i + 2 < expr.length()){
                            ++i;
                            ans += expr.charAt(i);
                        }

                        while(i + 2 < )

                        while(i + 2 < expr.length() || )
                    }else{
                        ans += "+";
                        flag = false;
                    }
                }

                if(i + 1 < expr.length()){


                    if(expr.charAt(i + 1) != '-' && expr.charAt(i + 1) != '+' && expr.charAt(i + 1) != '0'){
                        ans += "+";
                        flag = false;
                    }
                }else{
                    ans += "+";
                    flag = false;
                }
            }
        }
        writer.write(ans);
        writer.close();
    }
}
/*

*/