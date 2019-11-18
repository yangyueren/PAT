import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;

/*
* 用dfs
* 将当前要消去的city设置为已vist
* */
public class p1013 {
    public static void main(String[] args) throws Exception{
        p1013 p = new p1013();
        p.process();
    }
    int[][] map = new int[1010][1010];
    int[] visit = new int[1010];

    int N = 1010;
    public void process() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = br.readLine().split(" ");
        N = Integer.valueOf(inputs[0]);
        int M = Integer.valueOf(inputs[1]), K = Integer.valueOf(inputs[2]);
        for (int i = 0; i < M; i++) {
            inputs = br.readLine().split(" ");
            int begin = Integer.valueOf(inputs[0]);
            int end = Integer.valueOf(inputs[1]);
            map[begin][end] = 1;
            map[end][begin] = 1;
        }
        inputs = br.readLine().split(" ");
        for (int i = 0; i < K; i++) {

            int city = Integer.valueOf(inputs[i]);
            Arrays.fill(visit, 0);
            visit[city] = 1;
            int count = 0;
            for (int j = 1; j <= N; j++) {
                if (visit[j] != 1){
                    dfs(j);
                    count++;
                }

            }
            System.out.println(count-1);
        }
    }
    public void dfs(int city){
        visit[city] = 1;
        for (int i = 1; i <=N; i++) {
            if (map[city][i] != 0 && visit[i] != 1){
                dfs(i);
            }
        }
    }
}
