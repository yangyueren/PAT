import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class p1009 {
    public static void main(String[] args) {
        p1009 p = new p1009();
        p.process();
    }
    float[] a = new float[1001];
    float[] b = new float[1001];
    float[] c = new float[2004];
    public void process(){
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] a1 = br.readLine().split(" ");
            int k = Integer.valueOf(a1[0]);
            for (int i = 0; i < k; i++) {
                int exp = Integer.valueOf(a1[i*2+1]);
                float coff = Float.valueOf(a1[i*2+2]);
                a[exp] = coff;
            }
            a1 = br.readLine().split(" ");
            k = Integer.valueOf(a1[0]);
            for (int i = 0; i < k; i++) {
                int exp = Integer.valueOf(a1[i*2+1]);
                float coff = Float.valueOf(a1[i*2+2]);
                b[exp] = coff;
            }
        }catch (Exception e){

        }
//        for (int i = 0; i < 1001; i++) {
//            if (b[i] != 0) System.out.println(b[i]);
//        }
        calculate();
    }
    public void calculate(){
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++) {
                if (a[i] != 0 && b[j] != 0){
                    c[i+j] += a[i] * b[j];
                }
            }
        }

        DecimalFormat df = new DecimalFormat("#.0");
        int count = 0;
        String result = "";
        for (int i = 2003; i >= 0; i--) {
            if (c[i] != 0) {
                count++;
                result = result + " " + String.valueOf(i) + " " + df.format(c[i]);
            }
        }
        result = String.valueOf(count) + result;
        System.out.println(result);
    }


}
