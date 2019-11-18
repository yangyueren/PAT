import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p1008 {
    public static void main(String[] args) {
        p1008 p = new p1008();
        p.process();
    }
    public void process(){
        int[] stop = new int[200];
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] input = br.readLine().split(" ");
            int N = Integer.valueOf(input[0]);
            int time = 0;
            int now = 0;
            for (int i = 0; i < N; i++) {
                int next = stop[i] = Integer.valueOf(input[i+1]);
                if (next > now) time += 6*(next-now);
                else time += 4*(now-next);
                time += 5;
                now = next;
            }
            System.out.println(time);

        }catch (Exception e){

        }
    }
}
