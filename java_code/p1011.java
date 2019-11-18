import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.util.ArrayList;

public class p1011 {
    public static void main(String[] args) {
        p1011 p = new p1011();
        p.process();
    }
    public void process(){
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String re = "";
            ArrayList<Float> arrayList = new ArrayList<>();
            for (int i = 0; i < 3; i++) {
                //存下来这一行最大的数字 和 下标
                String[] line = br.readLine().split(" ");
                Integer index = 0;
                int j;
                for (j = 0; j < line.length; j++) {
                    Float now = Float.valueOf(line[j]);
                    if (now > Float.valueOf(line[index])){
                        index = j;
                        now = Float.valueOf(line[index]);
                    }
                }
                if (index==0) re += "W ";
                if (index==1) re += "T ";
                if (index==2) re += "L ";
                arrayList.add(Float.valueOf(line[index]));
            }
            Float d = (arrayList.get(0) * arrayList.get(1) * arrayList.get(2) * 0.65f -1) *2;
            BigDecimal bd = new BigDecimal(d);
            double de = bd.setScale(2, BigDecimal.ROUND_HALF_UP).doubleValue();
            System.out.println(re + de);

        }catch (Exception e){

        }
    }
}
