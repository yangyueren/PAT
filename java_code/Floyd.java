public class Floyd {
    public static void main(String[] args) {
        Floyd p = new Floyd();
        int N = 3;
        int[][] adj = p.newData(N);
        p.floydMinDis(adj, N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j<N; j++){
                System.out.printf("%d ", p.dis[i][j]);
            }
            System.out.println("");
        }
    }
    int[][] dis;
    int[][] path;
    /*
    * 有向图！三个for循环搞定，记得初始化*/
    public void floydMinDis(int[][] adj, int N){
        dis = new int[N][N];
        path = new int[N][N];
        for (int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++){
                dis[i][j] = adj[i][j];
                path[i][j] = -1;
            }
        }
        for(int k = 0; k < N; k++){
            for (int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++){
                    if (dis[i][j] > dis[i][k] + dis[k][j]){
                        dis[i][j] = dis[i][k]+dis[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
    }
    public int[][] newData(int N){
        int[][] adj = new int[N][N];
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                adj[i][j] = Integer.MAX_VALUE/3;
            }
        }
        adj[0][1] = 4;
        adj[0][2] = 7;
        adj[1][2] = 2;
        return adj;
    }
}
