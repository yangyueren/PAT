import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;

public class p1006{
    public static void main(String[] args) {
        p1006 p = new p1006();
        p.readData();

    }
    public void readData(){
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            List<Arriver> arrivers = new ArrayList<>();
            List<Arriver> leavers = new ArrayList<>();
            int repeat = Integer.valueOf(br.readLine());
            for (int i = 0; i < repeat; i++) {
                String[] cur = br.readLine().split(" ");
                arrivers.add(new Arriver(cur[0], cur[1]));
                leavers.add(new Arriver(cur[0], cur[2]));
            }
            Collections.sort(arrivers);
            Collections.sort(leavers);
            System.out.printf("%s %s", arrivers.get(0).id, leavers.get(leavers.size()-1).id);

        }catch (Exception e){
            System.out.println(e);
        }
    }
    class Arriver implements Comparable{
        String id;
        Date time;
        public Arriver(String id, String time){
            try {
                this.id = id;
                //HH是24小时，hh是12小时
                SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
                this.time = sdf.parse(time);
            }catch (Exception e){

            }

        }

        @Override
        public int compareTo(Object o) {
            if (o instanceof Arriver){
                if(this.time.before(((Arriver) o).time)){
                    return -1;
                }else {
                    return 1;
                }
            }
            return 0;
        }

    }
}