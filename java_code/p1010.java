import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p1010 {
    public static void main(String[] args) {
        p1010 p = new p1010();
        p.process();
    }
    public void process(){
        try {
            //需要用二分法做
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] input = br.readLine().split(" ");
            String a = "";
            String b = "";
            int radix = 0;
            if (input[2].equals("1")){
                a = input[0];
                b = input[1];
                radix = Integer.valueOf(input[3]);
            }else {
                b = input[0];
                a = input[1];
                radix = Integer.valueOf(input[3]);
            }
            int num = 0;
            for (int i = a.length()-1; i >= 0 ; i--) {
                char ch = a.charAt(i);
                if (ch >= '0' && ch <= '9'){
                    num += (int)Math.pow(radix, a.length() -1- i) * (ch-'0');
                }else {
                    num += (int)Math.pow(radix, a.length() -1- i) * (ch-'a');
                }
            }
            for (int j = 2; j < 36; j++) {
                int cur = 0;
                radix = j;
                for (int i = b.length()-1; i >= 0 ; i--) {
                    char ch = b.charAt(i);

                    if (ch >= '0' && ch <= '9'){
                        if (ch-'0' >= radix) continue;
                        cur += (int)Math.pow(radix, b.length() -1- i) * (ch-'0');
                    }else {
                        if (ch-'a'+10 >= radix) continue;
                        cur += (int)Math.pow(radix, b.length() -1- i) * (ch-'a'+10);
                    }
                }
                if (cur == num){
                    System.out.println(radix);
                    return;
                }
            }
            System.out.println("Impossible");

        } catch (Exception e) {

        }
    }
}
