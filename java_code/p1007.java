import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p1007 {
    public static void main(String[] args) {
        p1007 p = new p1007();
        p.process();
    }
    int[] arr;
    public void process(){
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int num = Integer.valueOf(br.readLine());
            String[] strings = br.readLine().split(" ");
            arr = new int[num];
            for (int i = 0; i < num; i++) {
                arr[i] = Integer.parseInt(strings[i]);
            }
            int final_l = 0;
            int final_r = num-1;
            int start_index = 0;
            int sub_sum = 0;
            int final_sum = Integer.MIN_VALUE;
            for (int i = 0; i < num; i++) {
                int temp = arr[i];
                sub_sum += temp;
                if (sub_sum >= 0){
                    if (sub_sum > final_sum){
                        final_sum = sub_sum;
                        if (final_l != start_index){
                            final_l = start_index;
                        }
                        final_r = i;
                    }
                }else {
                    sub_sum = 0;
                    start_index = i+1;
                }
            }
            if (final_sum >= 0){
                System.out.printf("%d %d %d", final_sum, arr[final_l], arr[final_r]);
            }
            else {
                final_sum = 0;
                System.out.printf("%d %d %d", final_sum, arr[0], arr[num-1]);
            }


        } catch (Exception e) {

        }
    }

}
