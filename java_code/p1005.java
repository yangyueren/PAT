import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

public class p1005 {
    public static void main(String[] args) {
        p1005 p = new p1005();
        p.process();
    }
    public void process(){
        map.put('0', "zero");
        map.put('1', "one");
        map.put('2', "two");
        map.put('3', "three");
        map.put('4', "four");
        map.put('5', "five");
        map.put('6', "six");
        map.put('7', "seven");
        map.put('8', "eight");
        map.put('9', "night");
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            char[] line = br.readLine().toCharArray();
            BigInteger re = new BigInteger("0");
            for (int i = 0; i < line.length; i++) {
                re = re.add(new BigInteger(String.valueOf(line[i] - '0')));
            }
            line = re.toString().toCharArray();
            for (int i=0; i < line.length; i++){
                if (i != 0){
                    System.out.print(" ");
                }
                System.out.print(map.get(line[i]));
            }
        }catch (Exception e){
            System.out.println(e.toString());
        }

    }
    Map<Character, String> map = new HashMap<>();
}
