import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class p1003 {
    public static void main(String[] args){
        p1003 p = new p1003();
        p.readData();
        p.djistra();
        System.out.printf("%d %d", p.npath[p.c2], p.meet_people[p.c2]);
    }

    int N, M, c1, c2;
    int[][] graph;
    int[] people;
    int[] dis;
    int[] npath;
    int[] meet_people;
    boolean[] visit;

    public void djistra(){
        dis = new int[N];
        meet_people = new int[N];
        npath = new int[N];
        visit = new boolean[N];
        for (int i = 0; i < N; i++) {
            dis[i] = Integer.MAX_VALUE;
            visit[i] = false;
        }
        dis[c1] = 0;
        npath[c1] = 1;
        //forget the below line
        meet_people[c1] = people[c1];
        int count = N;
        while (count-- > 0){
            int min = Integer.MAX_VALUE;
            int now = -1;
            //找出全部节点中：没有访问过 && 距离最小
            for (int i = 0; i < N; i++) {
                //必须是没有visit过的
                if (dis[i] < min && !visit[i]){
                    now = i;
                    min = dis[i];
                }
            }
//            if (now == -1 || now == c2)
//                return;

            visit[now] = true;

            for (int i = 0; i < N; i++) {
                //如果是0，代表不相邻
                //如果是visit 或者 不相邻
                if (visit[i] || graph[now][i] == 0){
                    continue;
                }
                if (dis[i] > graph[now][i] + dis[now]){
                    dis[i] = graph[now][i] + dis[now];
                    npath[i] = npath[now];
                    meet_people[i] = meet_people[now] + people[i];
                }else if (dis[i] == graph[now][i] + dis[now]){
                    //npath means how many ways you can go, but you can only choose one in the end
                    npath[i] = npath[i] + npath[now];
                    //this line is important because you can only collect the people on one path.
                    if (meet_people[i] < meet_people[now] + people[i]){
                        meet_people[i] = meet_people[now] + people[i];
                    }
//                    meet_people[i] = (meet_people[i] >= meet_people[now] + people[i]) ? meet_people[i] : meet_people[now] + people[i];
                }
            }


        }

    }
    public void readData(){
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] line = br.readLine().split(" ");
            N = Integer.valueOf(line[0]);
            M = Integer.valueOf(line[1]);
            c1 = Integer.valueOf(line[2]);
            c2 = Integer.valueOf(line[3]);
            graph = new int[N][N];
            people = new int[N];
            line = br.readLine().split(" ");
            for (int i = 0; i < line.length; i++) {
                people[i] = Integer.valueOf(line[i]);
            }
            for (int i = 0; i < M; i++) {
                line = br.readLine().split(" ");
                int v1 = Integer.valueOf(line[0]);
                int v2 = Integer.valueOf(line[1]);
                int w = Integer.valueOf(line[2]);
                graph[v1][v2] = w;
                graph[v2][v1] = w;
            }

        }catch (Exception e){
            System.out.println(e);
        }

    }
}
