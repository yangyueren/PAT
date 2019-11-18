import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*设立c数组，长度为指数的最大值，c[i] = j表示指数i的系数为j，
接收a和b输入的同时将对应指数的系数加入到c中，累计c中所有非零系数的个数，然后从前往后输出所有系数不为0的指数和系数～
* */
public class p1002p {
    public static void main(String[] args) {
        p1002p p = new p1002p();
        try {

            String re = p.readData();
            System.out.println(re);

        }catch (Exception e){

        }

    }
    private int maxsize = 1001;
    public double[] cnt = new double[maxsize];
    private String readData() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int k = Integer.valueOf(line[0]);
        double a;
        int n;
        for (int i = k; i >= 1; i--) {
            n = Integer.valueOf(line[2*i-1]);
            a = Double.valueOf(line[2*i]);
            cnt[n] += a;
        }
        line = br.readLine().split(" ");
        k = Integer.valueOf(line[0]);
        for (int i = k; i >= 1; i--) {
            n = Integer.valueOf(line[2*i-1]);
            a = Double.valueOf(line[2*i]);
            cnt[n] += a;
        }

        int count = 0;
        for (int i = 0; i < 1001; i++) {
            if (cnt[i] != 0){
                count++;
            }
        }
        String re = String.valueOf(count);
        for (int i = maxsize-1; i >= 0; i--) {
            if (cnt[i] != 0.0){
                re += " ";
                re += String.valueOf(i);
                re += " ";
                re += String.valueOf(Math.round(cnt[i]*10)/10.0);
            }
        }
        return re;

    }
}
