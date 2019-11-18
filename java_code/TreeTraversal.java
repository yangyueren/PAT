import java.util.*;

public class TreeTraversal {
    public static void main(String[] args) {
        TreeTraversal p = new TreeTraversal();
        Node root = p.buildTree();
        p.inOrderIter(root);
//        p.seqTraversing(root);
        for (int i = 0; i < p.result.size(); i++) {
            System.out.println(p.result.get(i));
        }
    }
    public Node buildTree(){
        Node root = new Node(1);
        root.left = new Node(2);
        root.left.right = new Node(3);
        root.right = new Node(4);
        root.right.left = new Node(5);
        root.right.right = new Node(6);

        return root;
    }
    public ArrayList<Integer> result = new ArrayList<>();

    public void seqTraversing(Node root){
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        Node cur;
        while (queue.size() > 0){
            cur = queue.poll();
            if (cur.left != null) queue.offer(cur.left);
            if (cur.right != null) queue.offer(cur.right);
            result.add(cur.val);
        }
    }
    public void inOrderIter(Node root){
        if (root == null) return;
        Stack<Node> stack = new Stack<>();
        Node cur = root;
        while (stack.size() > 0 || cur != null){
            if (cur != null){
                stack.push(cur);
                cur = cur.left;
            }else {
                cur = stack.pop();
                result.add(cur.val);
                cur = cur.right;
            }
        }
    }
    /*
    public void inOrderIter(Node root){
        if (root == null) return;
        Node now = root;
        Stack<Node> stack = new Stack<>();
        while (stack.size() > 0 || now != null){
            if (now != null){
                stack.push(now);
                now = now.left;
            }
            else {
                now = stack.pop();
                result.add(now.val);
                now = now.right;
            }
        }
    }
    */
    /*
    public void inOrderIter(Node root){
        if (root == null) return;
        Stack<Node> stack = new Stack<>();
        //important
        Node now = root;
        //
        //stack.push(root)   //这样是错误的，因为else代表该节点左子树已经被遍历了
        while (stack.size() > 0 || now != null){
            if (now != null){
                stack.push(now);
                now = now.left;
            }
            else {
                now = stack.pop();
                result.add(now.val);
                now = now.right;
            }
        }
    }
    */

    public void inOrder(Node root){
        if (root == null){
            return;
        }
        else {
            inOrder(root.left);
            result.add(root.val);
            inOrder(root.right);
        }
    }

    class Node{
        public Node left;
        public Node right;
        int val;
        public Node(int val){
            this.val = val;
            this.left = null;
            this.right = null;
        }
    }
}
