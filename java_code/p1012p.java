import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.Struct;
import java.util.*;

/*
 * 目前出错的地方，是没有考虑并列，以及超时。*/
public class p1012p{

    public static void main(String[] args) throws Exception {
        p1012p p = new p1012p();
        p.process();
    }
    int flag = 0;
    int[] exist = new int[1000000];
    public void process() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.valueOf(input[0]), m = Integer.valueOf(input[1]);
        List<Student> students = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            students.add(new Student(input));
        }
        for (int i = 0; i < 4; i++) {
            flag = i;
            Collections.sort(students);
            int count = 1;
            students.get(0).rank[flag] = 1;
            exist[students.get(0).id] = 1;
            for (int j = 1; j < students.size(); j++) {
                exist[students.get(j).id] = j+1;
                if (students.get(j).score[flag] == students.get(j-1).score[flag]){
                    students.get(j).rank[flag] = students.get(j-1).rank[flag];
                }else {
                    students.get(j).rank[flag] = j+1;

                }
            }
        }
        for (int i = 0; i < students.size(); i++) {
            exist[students.get(i).id] = i+1;
            students.get(i).best = choose_best_rank(students.get(i));
        }
        for (int i = 0; i < m; i++) {
            int id = Integer.valueOf(br.readLine().split(" ")[0]);

            if (exist[id] != 0){
                int index = exist[id];
                Student student = students.get(index-1);
                int best = student.best;
                int rank = student.rank[best];
                if (best == 0) System.out.println( rank+ " A");
                if (best == 1) System.out.println( rank+" C");
                if (best == 2) System.out.println( rank+" M");
                if (best == 3) System.out.println( rank + " E");

            }else {
                System.out.println("N/A");
            }

        }


    }
    public int choose_best_rank(Student student){
        int min = 0;
        for (int i = 1; i < 4; i++) {
            if (student.rank[min] > student.rank[i]){
                min = i;
            }
        }
        return min;
    }
    class Student implements Comparable{
        int id;
        int best;
        int[] score = new int[4];
        int[] rank = new int[4];
        Student(String[] input){
            id = Integer.valueOf(input[0]);
            score[1] = Integer.valueOf(input[1]);
            score[2] = Integer.valueOf(input[2]);
            score[3] = Integer.valueOf(input[3]);
            score[0] = (int)((score[1] + score[2] + score[3])*1.0/3);
        }

        @Override
        public int compareTo(Object o) {
            Student b = (Student)o;
            if (this.score[flag] < b.score[flag]){
                return 1;
            }else {
                return -1;
            }
        }
    }
}
