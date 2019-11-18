/*
dijkstra 单源无负权，时间复杂的小。


bellmanford单源，可以检测负权重。
    i, j, k
    //i 对应的是对所有边做一次松弛操作
    //内两层循环：每次松弛j-k这条边
    d[k] = Math.min(d[k], d[j]+a[j][k])
    对于一个图G(v,e)(v代表点集，e代表边集)，执行|v|-1次边集的松弛操作，所谓松弛操作，就是对于每个边e1(v,w)，将源点到w的距离更新为：
    原来源点到w的距离 和 源点到v的距离加上v到w的距离
    
    没有负环的情况：我们现在已经证明了路径松弛性质，那么显而易见，在没有负环的时候，一个图中的两个节点s,u的最短路径v0->v1,v1->v2,…..vk-1->vk为简单路径（即没有环的路径），所以对于节点数目为|V|的图，s,u的最短路径，最多有|V|-1条边，即k<=|V|-1。我们在算法中，一共进行了|V|-1次所有边的松弛操作，因为每次对所有的边进行松弛，所以对于最短路中第i条路径vi-1->vi，一定在第i次松弛操作中被松弛了，那么根据松弛路径性质，在进行|V|-1次所有边的松弛操作之后，毕竟得到所有点的最短路径。

    负环的判断：如果有源点可达的负环，说明源点到某点的最短路径不是简单路径（不断走负环达到负无穷），因此在第|V|次松弛的时候，还能被松弛，因此在第|V|次松弛的时候，还能被松弛，就说明有负环存在。
    
    
floyd，多源无负权，k放到最外层，才可以无后效性。基于dp。
floyd 十字算法
    k, i, j
    dis[i][j] = Math.min(dis[i][j], dis[i][k]+dis[k][j])
    
    定义状态，划分阶段，我们定义 f[k][i][j]为经过前k的节点，从i到j所能得到的最短路径，
    f[k][i][j]可以从f[k-1][i][j]转移过来，即不经过第k个节点，
    也可以从f[k-1][i][k]+f[k-1][k][j]转移过来，即经过第k个节点。
    观察一下这个状态的定义，满足不满足最优子结构和无后效性原则。
    
*/
public class BellmanFord {
    public static void main(String[] args) {
        BellmanFord p = new BellmanFord();

    }
    int[] dis;
    int[][] adj;
    /*
    * return 是否有负边 0代表没有*/
    public int bellman_ford(int s, int N){
        int flag=0;
        for (int i = 0; i < N; i++) {
            dis[i] = Integer.MAX_VALUE;
        }
        dis[s] = 0;

        for (int i = 0; i < N; i++) {
            flag = 0;
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    //每次松弛j-k这条边
                    if (dis[k] > dis[j] + adj[j][k]){
                        dis[k] = dis[j] + adj[j][k];
                        flag = 1;
                    }
                }
            }
            if (flag == 0) return 0;
        }
        return 1-flag;
//        flag = 0;
//        for(int j = 0; j < N; j++){
//            for(int k = 0; k < N; k++){
//                if (dis[k] > dis[j] + adj[j][k]){
//                    dis[k] = dis[j] + adj[j][k];
//                    flag = 1;
//                }
//            }
//        }
//        return 1-flag;
    }
}
