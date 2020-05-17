import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        File file = new File("alex.in");
        BufferedWriter writer = new BufferedWriter(new FileWriter("alex.out"));
        Scanner sc = new Scanner(file);
        int h, w, t;
        h = sc.nextInt();
        w = sc.nextInt();
        if(h > w){
            t = h;
            h = w;
            w = t;
        }
        double ans = Math.max(Math.min(w / 3.0, h), h / 2.0);
        writer.write(String.format("%.6f", ans));
        writer.close();
    }
}
/*

*/