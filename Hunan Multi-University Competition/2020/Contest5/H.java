 import java.io.*;
 import java.lang.reflect.Array;
 import java.util.*;


public class Main {
    private static ArrayList<String> ans = new ArrayList<>();

    static void generateAllBinaryStrings(int n, int arr[], int i){
        if(ans.size() >= 1000)  return;

        if(i == n){
            String s = "";
            for(int j = 0; j < n; ++j){
                if(arr[j] == 0)  s += "Aa";
                else s += "BB";
            } 
            ans.add(s);
            return;
        }

        arr[i] = 0;
        generateAllBinaryStrings(n, arr, i + 1);

        arr[i] = 1;
        generateAllBinaryStrings(n, arr, i + 1);
    }

    private static void init(){
        ans.clear();
        int n = 10;
        int[] arr = new int[n];
        generateAllBinaryStrings(n, arr, 0);
    }

    public static void main(String[] args) throws IOException {

//        File file = new File("data/alex.in");
        File file = new File("hash.in");
        BufferedWriter writer = new BufferedWriter(new FileWriter("hash.out"));
//        BufferedWriter writer = new BufferedWriter(new FileWriter("data/alex.out"));
        Scanner sc = new Scanner(file);

        init();
        int k = sc.nextInt();

        for(int i = 0; i < k; ++i){
            writer.write(ans.get(i) + '\n');
        }
        writer.close();
    }
}
