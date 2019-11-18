//import java.io.BufferedReader;
//import java.io.InputStreamReader;
//import java.io.IOException;
//
//public class p1002{
//    public static void main(String[] args) {
//        p1002 p = new p1002();
//        try {
//            p.readData();
//            String re = p.add();
//            System.out.println(re);
//        }catch (Exception e){
//
//        }
//
//    }
//    private String add(){
//        Integer[] N = new Integer[22];
//        Double[] a = new Double[22];
//        String re = "";
//        int p1 = 0;
//        int p2 = 0;
//        int p = 0;
//        while (p1 < pp1 && p2 < pp2){
//            if (N1[p1] == N2[p2]){
//                N[p] = N1[p1];
//                a[p] = a1[p1] + a2[p2];
//                p1++;
//                p2++;
//                p++;
//            }else if (N1[p1] < N2[p2]){
//                N[p] = N1[p1];
//                a[p] = a1[p1];
//                p1++;
//                p++;
//            }else if (N1[p1] > N2[p2]){
//                N[p] = N2[p2];
//                a[p] = a2[p2];
//                p2++;
//                p++;
//            }
//        }
//        while (p1<pp1){
//            N[p] = N1[p1];
//            a[p] = a1[p1];
//            p1++;
//            p++;
//        }
//        while (p2<pp2){
//            N[p] = N2[p2];
//            a[p] = a2[p2];
//            p2++;
//            p++;
//        }
////        System.out.println(re);
//        re += String.valueOf(p);
//        re += " ";
//        for (int i = p-1; i >= 0; i--) {
//            re += String.valueOf(N[i]);
//            re += " ";
//            re += String.valueOf(Math.round(a[i]*10)/10.0);
////            double aa = a[i];
////            if (aa >= 10){
////                if (i > 0 && N[i-1] = N[i])
////            }
//
//            if (i != 0){
//                re += " ";
//            }
//        }
////        System.out.println(re);
//        return re;
//    }
//
//    private Integer MAXN = 11;
//    private Integer[] N1 = new Integer[MAXN];
//    private Double[] a1 = new Double[MAXN];
//    private Integer[] N2 = new Integer[MAXN];
//    private Double[] a2 = new Double[MAXN];
//    int pp1 = 0;
//    int pp2 = 0;
//    private void readData() throws IOException{
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        String[] line = br.readLine().split(" ");
//        int k = Integer.valueOf(line[0]);
//        pp1 = k;
//        for (int i = k; i >= 1; i--) {
//            N1[k-i] = Integer.valueOf(line[2*i-1]);
//            a1[k-i] = Double.valueOf(line[2*i]);
//        }
//        line = br.readLine().split(" ");
//        k = Integer.valueOf(line[0]);
//        pp2 = k;
//        for (int i = k; i >= 1; i--) {
//            N2[k-i] = Integer.valueOf(line[2*i-1]);
//            a2[k-i] = Double.valueOf(line[2*i]);
//        }
//    }
//}
