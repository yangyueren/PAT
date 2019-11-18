import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Kruskal {
    public static void main(String[] args) {
        Kruskal p = new Kruskal();
        p.minGT(7);

    }
    List<Edge> graph;
    int[] parent;
    public void minGT(int n){
        graph = new ArrayList<>();
        initGraph(n);
        Collections.sort(graph);
        List<Edge> minTree = new ArrayList<>();

        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < graph.size(); i++) {
            Edge e = graph.get(i);
            int a = e.begin;
            int b = e.end;
            int w = e.w;
            if (find(a) != find(b)){
                union(a, b);
                minTree.add(e);
            }

        }
        for (int i = 0; i < minTree.size(); i++) {
            System.out.println(minTree.get(i));
        }


    }
    public void initGraph(int n){
        graph.add(new Edge(0,1,7));
        graph.add(new Edge(1,2,8));
        graph.add(new Edge(0,3,5));
        graph.add(new Edge(1,4,7));
        graph.add(new Edge(3,4,15));
        graph.add(new Edge(1,3,9));
        graph.add(new Edge(3,5,6));
        graph.add(new Edge(4,5,8));
        graph.add(new Edge(4,6,9));
        graph.add(new Edge(5,6,11));
        graph.add(new Edge(2,4,5));
    }
    public void union(int x, int y){
        int a = find(x);
        int b = find(y);
        parent[a] = b;
    }
    public int find(int x){
        while (x != parent[x]){
            x = parent[x];
        }
        return x;
    }
    class Edge implements Comparable{
        public int begin;
        public int end;
        public int w;
        public Edge(int a, int b, int w){
            this.begin = a;
            this.end = b;
            this.w = w;
        }

        @Override
        public String toString() {
            String re = String.format("%d -> %d,  weight is %d:", begin, end, w);
            return re;
        }

        @Override
        public int compareTo(Object o) {
            if (o instanceof Edge){
                return this.w - ((Edge) o).w;
            }
            return 0;
        }
    }
}
