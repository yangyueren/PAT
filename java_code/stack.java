import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class stack {
    public static void main(String[] args) {
        Stack<Integer> a = new Stack<>();
        a.push(1);
        a.push(2);
        a.push(3);
        System.out.println(a.search(2));
        System.out.println(a.pop());
        System.out.println(a.pop());

        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        q.offer(2);
        q.offer(3);
        System.out.println(q.peek());
        System.out.println(q.poll());
        System.out.println(q.poll());
    }
}
