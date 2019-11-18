public class heapSort {
    public static void main(String[] args) {
        int[] a = {2,4,7,9,3,8,1};
        heapSort.heapsort(a, a.length-1);
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
    public static void heapsort(int[] s, int length){
        for (int i = length/2-1; i > 0; i--) {
            minHeapFixDown(s, i, length);
        }
        for (int i = 0; i < length; i++) {
            int temp = s[0];
            s[0] = s[length-i-1];
            s[length-i-1] = temp;
            minHeapFixDown(s, 0, length-i-1);
        }
    }
    /*
    * n 是数组元素数量
    * minHeap 排序是从大到小*/
    public static void minHeapFixDown(int[] s, int x, int n){
        int val = s[x];
        int j = 2*x+1;
        while (j<n){
            if (j+1<n && s[j+1] < s[j]){
                j = j+1;
            }
            if (s[j] < val){
                s[x] = s[j];
//                s[j] = val;
                x = j;
                j = 2*x+1;
            }else {

                break;
            }
        }
        s[x] = val;
    }
    /*
    public static void minHeapFixDown(int[] s, int x, int n){
        int val = s[x];
        int j = 2*x+1;
        while (j < n){
            if (j+1<n && s[j+1] < s[j])
                j = j+1;
            if (s[j] < val){
                s[x] = s[j];
                x = j;
                j = 2*x+1;
            }else {
                break;
            }
        }
        s[x] = val;
    }
    */
/*
    public static void minHeapFixDown(int[] s, int i, int n){
        int down = s[i];
        int j = 2*i+1;
        //本质上是在和子节点交换
        while (j<n){
            if (j+1 < n && s[j] > s[j+1]){
                j = j+1;
            }
            //这里必须要有，因为如果没有，j有可能不进入下面的if分支，j的值就不会变。
            //这里应该是<= 如果相等，陷入死循环
            if (down <= s[j]){
                break;
            }
            if (down > s[j]){
                s[i] = s[j];
                s[j] = down;
                i = j;
                j = 2 * i + 1;
            }
        }
    }
    */
}
