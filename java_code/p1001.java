import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;

public class p1001 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        String[] split = br.readLine().split(" ");
//        Integer x = Integer.valueOf(split[0]) + Integer.valueOf(split[1]);
//        Integer x = Integer.MAX_VALUE;
        double x = 3.3;
        //不能四舍五入
        DecimalFormat format = new DecimalFormat("00.00");
        String result = format.format(x);
        System.out.println(result);


        String a = "32.3";
        //可以四舍五入
        BigDecimal bf = new BigDecimal(a);
        double re = bf.setScale(2, BigDecimal.ROUND_HALF_UP).doubleValue();
        System.out.println(re);

    }
}
