import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.*;

public class p1016 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws Exception{
        p1016 p = new p1016();
        p.process();
    }
    int[] billrate = new int[25];
    int total_call = 0;
    List<Call> calls = new ArrayList<>();
    Map<String, List<Node>> map = new HashMap<>();

    public void process() throws Exception{
        String[] inputs = br.readLine().split(" ");
        for (int i = 0; i < inputs.length; i++) {
            billrate[i] = Integer.valueOf(inputs[i]);
            billrate[24] += billrate[i];
        }
        total_call = Integer.valueOf(br.readLine());
        for (int i = 0; i < total_call; i++) {
            inputs = br.readLine().split(" ");
            calls.add(new Call(inputs));
        }
        Collections.sort(calls);
        for (int i = 1; i < calls.size(); i++) {
            Call pre = calls.get(i-1);
            Call now = calls.get(i);
            if (pre.name.equals(now.name) && pre.status.equals("on-line") && now.status.equals("off-line")){
                if (map.containsKey(now.name)){
                    List<Node> list = map.get(now.name);
                    list.add(new Node(calls.get(i-1), calls.get(i)));
                }else {
                    List<Node> list = new ArrayList<>();
                    list.add(new Node(calls.get(i-1), calls.get(i)));
                    map.put(now.name, list);
                }
            }
        }
        Object[] key =  map.keySet().toArray();
        Arrays.sort(key);

        for (int i = 0; i < map.size(); i++){
            String k = (String)key[i];
            List<Node> list = map.get(k);
            double total = 0;
            DecimalFormat format = new DecimalFormat("00");

            System.out.println(k +" "+ format.format(list.get(0).month));
            for (int j = 0; j < list.size(); j++) {

                System.out.println(list.get(j).getResult());
                total += list.get(j).price;
            }
            DecimalFormat format1 = new DecimalFormat("##.00");
            System.out.println("Total amount: $"+format1.format(total));
        }
    }
    class Node{

        int month;
        int days;
        int hour;
        int minute;
        int days2;
        int hour2;
        int minute2;

        int total;
        double price;
        Node(Call call1, Call call2){
            month = call1.month;
            days = call1.days;
            hour = call1.hour;
            minute = call1.minute;
            days2 = call2.days;
            hour2 = call2.hour;
            minute2 = call2.minute;
            total = call2.current_time - call1.current_time;
            price = billFromZero(call2) - billFromZero(call1);

        }
        public String getResult(){
            String result = "";
            DecimalFormat format = new DecimalFormat("00");
            DecimalFormat format1 = new DecimalFormat("##.00");
            result += format.format(days)+":"+format.format(hour)+":"+format.format(minute)+" ";
            result += format.format(days2)+":"+format.format(hour2)+":"+format.format(minute2)+" "+total+" $"+format1.format(price);
            return result;
        }
    }
    double billFromZero(Call call){
        double total = billrate[call.hour] * call.minute + billrate[24]*call.days*60;
        for (int i = 0; i < call.hour; i++) {
            total += billrate[i]*60;
        }

        DecimalFormat format = new DecimalFormat("##.00");
        String result = format.format(total/100);
        return Double.valueOf(result);

    }
    class Call implements Comparable{
        String name;
        int month;
        int days;
        int hour;
        int minute;
        int current_time;
        String  status;
        Call(String[] inputs){
            this.name = inputs[0];
            this.status = inputs[2];
            String[] times = inputs[1].split(":");
            this.month = Integer.valueOf(times[0]);
            this.days = Integer.valueOf(times[1]);
            this.hour = Integer.valueOf(times[2]);
            this.minute = Integer.valueOf(times[3]);
            current_time = days*24*60 + hour*60 + minute;
        }
        @Override
        public int compareTo(Object o) {
            Call call = (Call)o;
            if (this.name.compareTo(call.name) != 0){
                return this.name.compareTo(call.name);
            }else {
                return this.current_time - call.current_time;
            }
        }
        @Override
        public String toString(){
            String re = "";
            re += this.name +" "+ current_time+" "+this.days+" "+this.hour+" "+this.minute;
            return re;
        }
    }
}
