public class UnionFind {
    public static void main(String[] args){
        UnionFind p = new UnionFind();
        p.union(2,3);
        p.union(2,4);
        p.union(0,1);
        p.find(2);
        for (int i = 0; i < 5; i++) {
            System.out.println(p.parent[i]);
//            System.out.println(p.find(i));
        }
    }
    int[] parent = new int[100];
    public UnionFind(){
        for (int i = 0; i < 100; i++) {
            parent[i] = i;
        }
    }
    public void union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        parent[rootx] = rooty;
    }
    //压缩路径
    public int find(int x){
        int r = x;
        while (r != parent[r]){
            r = parent[r];
        }
        int j = x;
        int t;
        while (j != r){
            t = parent[j];
            parent[j] = r;
            j = t;
        }
        return r;
    }
    /*
    public int find(int x){
        int r = x;
        while (r != parent[r]){
            r = parent[r];
        }
        int j = x;
        while (j != r){
            int par = parent[j];
            parent[j] = r;
            j = par;
        }
        return r;
    }
    */
    /*
    public int find(int x){
        int r = x;
        while (r != parent[r]){
            r = parent[r];
        }
        int j = x;
        int par;
        while (j != r){
            par = parent[j];//j的父亲节点
            parent[j] = r;//j指向根节点
            j = par;//j移动到父亲节点
        }
        return r;
    }
    */
    /*
    * 可能会爆栈*/
//    public int find(int x){
//        while (x != parent[x]){
//            x = find(parent[x]);
//        }
//        return parent[x];
//    }

    /*
    * 没有路径压缩*/
//    public int find(int x){
//        int r = x;
//        while (parent[r] != r){
//            r = parent[r];
//        }
//        return r;
//    }
}
