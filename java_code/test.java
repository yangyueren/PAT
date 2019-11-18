import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Date;

public class test {
    public static void main(String[] args) throws Exception{
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        Date a1 = sdf.parse("2019-09-19");
        Date a2 = sdf.parse("2019-07-19");
        System.out.println(a1);
        System.out.println(a2.toString());
        System.out.println(a1.before(a2));

    }
}
