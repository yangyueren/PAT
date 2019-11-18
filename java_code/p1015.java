import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Map;

/*1不是素数； 记得判断*/
public class p1015 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception{
        while (true){
            String input = br.readLine();
            if (!input.contains(" ")){
                return;
            }
            String[] inputs = input.split(" ");
            p1015 p = new p1015();
            p.process(inputs);
        }
    }
    public void process(String[] inputs){
        int a = Integer.valueOf(inputs[0]);
        int aa = a;
        int radix = Integer.valueOf(inputs[1]);
        int[] reverse = new int[10000];
        int count = 0;
        do {
            reverse[count] = a % radix;
            a /= radix;
            count++;
        }while (a!= 0);
        count--;
        int d = 0;
        for (int i = 0; i <= count; i++) {
            d += Math.pow(radix, count-i) * reverse[i];
        }
//        System.out.println(d);
        if(judge(aa) && judge(d)){
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }

    }
    boolean judge(int a){
        /*
        * 1不是素数*/
        if (a <= 1) return false;
        for (int i = 2; i <= Math.sqrt(a); i++) {
            if (a % i == 0){
                return false;
            }
        }
        return true;
    }
}
