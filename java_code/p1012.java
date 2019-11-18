import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
* 目前出错的地方，是没有考虑并列，以及超时。*/
public class p1012{

    public static void main(String[] args) throws Exception{
        p1012 p = new p1012();
        p.process();
    }
    public void process() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.valueOf(input[0]), m = Integer.valueOf(input[1]);
        Map<Integer, Double> ascore = new HashMap<>();
        Map<Integer, Integer> cscore = new HashMap<>();
        Map<Integer, Integer> mscore = new HashMap<>();
        Map<Integer, Integer> escore = new HashMap<>();
        for (int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            cscore.put(Integer.valueOf(input[0]), Integer.valueOf(input[1]));
            mscore.put(Integer.valueOf(input[0]), Integer.valueOf(input[2]));
            escore.put(Integer.valueOf(input[0]), Integer.valueOf(input[3]));
            int total = Integer.valueOf(input[1]) + Integer.valueOf(input[2]) +Integer.valueOf(input[3]);
            ascore.put(Integer.valueOf(input[0]), total * 1.0 / 3.0);
        }
        MyComparator myComparator = new MyComparator();
        List<Map.Entry<Integer, Integer>> clist = new ArrayList<Map.Entry<Integer, Integer>>(cscore.entrySet());
        clist.sort(myComparator);
        List<Map.Entry<Integer, Integer>> mlist = new ArrayList<Map.Entry<Integer, Integer>>(mscore.entrySet());
        mlist.sort(myComparator);
        List<Map.Entry<Integer, Integer>> elist = new ArrayList<Map.Entry<Integer, Integer>>(escore.entrySet());
        elist.sort(myComparator);
        List<Map.Entry<Integer, Double>> alist = new ArrayList<Map.Entry<Integer, Double>>(ascore.entrySet());
        alist.sort(new MyComparator2());
//        for (int i = 0; i < n; i++) {
//            System.out.println(alist.get(i).getValue());
//        }

        for (int i = 0; i < m; i++) {
            Integer id = Integer.valueOf(br.readLine().split(" ")[0]);
            int ai = -1, ci = -1, mi = -1, ei = -1;
            for (int j = 0; j < n; j++) {
                if (alist.get(j).getKey().equals(id)) ai=j;
                if (clist.get(j).getKey().equals(id)) ci=j;
                if (mlist.get(j).getKey().equals(id)) mi=j;
                if (elist.get(j).getKey().equals(id)) ei=j;
            }
            if (ai==-1 && ci==-1 && mi==-1 && ei==-1) {
                System.out.println("N/A");
                continue;
            }
            if (ai<=ci && ai<=mi && ai<= ei){
                System.out.println(ai+1 + " " + "A");
                continue;
            }
            if (ci<ai && ci<=mi && ci<= ei){
                System.out.println(ci+1 + " " + "C");
                continue;
            }
            if (mi<ai && mi<ci && mi<= ei){
                System.out.println(mi+1 + " " + "M");
                continue;
            }
            if (ei<ci && ei<mi && ei< ai){
                System.out.println(ei+1 + " " + "E");
                continue;
            }

        }

    }

}

class MyComparator implements Comparator<Map.Entry<Integer, Integer>>{
    @Override
    public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
        //大于0 交换
        return o2.getValue() - o1.getValue();
    }
}
class MyComparator2 implements Comparator<Map.Entry<Integer, Double>>{
    @Override
    public int compare(Map.Entry<Integer, Double> o1, Map.Entry<Integer, Double> o2) {
        if (o1.getValue().equals(o2.getValue())) return 0;
        return (o2.getValue() - o1.getValue()) > 0 ? 1 : -1;
    }
}