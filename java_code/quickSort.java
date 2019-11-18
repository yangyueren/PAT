public class quickSort {
    public static void main(String[] args) {
        int[] a = {2,4,7,3,8,1};
        quickSort.quicksort(a, 0, a.length-1);
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
    static void quicksort(int[] s, int l, int r){
        if (l < r){
            int i = l, j = r;
            int mid = s[l];
            while (i < j){
                while (i<j&&mid<s[j]) j--;
                if (i<j) s[i] = s[j];
                while (i<j&&s[i]<mid) i++;
                if (i<j) s[j] = s[i];
            }
            s[i] = mid;
            quicksort(s, l, i-1);
            quicksort(s, i+1, r);
        }
    }
    /*
    static void quicksort(int[] s, int l, int r){
        //递归一定要写return条件
        if (l >= r) return;
        if (l < r){
            int i = l, j = r;
            int x = s[l];
            while (i < j){
                while (i<j && x < s[j]) j--;
                if (i<j) s[i++] = s[j];
                while (i<j && s[i] < x) i++;
                if (i<j) s[j--] = s[i];
            }
            s[i] = x;
            quicksort(s, l, i-1);
            quicksort(s, i+1, r);
        }

    }
    */
    /*
    static void quicksort(int s[], int l, int r){
        if (l < r){
            int mid = s[l];
            int i = l;
            int j = r;
            while (i < j){
                while (i < j && mid <= s[j]){
                    j--;
                }
                if (i < j){
                    s[i++] = s[j];
                }
                while (i < j && s[i] <= mid){
                    i++;
                }
                if (i < j){
                    s[j--] = s[i];
                }
            }
            s[i] = mid;
            quicksort(s, l, i-1);
            quicksort(s, i+1, r);
        }

    }
    */
    /*
    static void quicksort(int s[], int l, int r) {
        if (l < r){
            int mid = s[l];
            int i = l, j = r;
            while (i < j){
                //这里的i<j必须有，是因为一开始序列是 0，1，2，3这样的顺序的，那么j会减到-1
                while (i < j && mid <= s[j])
                    j--;
                //这里的if(i<j)必须有，是因为如果从while出来的i==j，此时应该break的，如果没有if，会执行s[i++] = s[j]破坏了i
                if (i<j) s[i++] = s[j];
                while (i < j && mid >= s[i])
                    i++;
                if (i<j) s[j--] = s[i];
            }
            s[i] = mid;

            quicksort(s, l, i-1);
            quicksort(s, i+1, r);
        }
    }
    */
}
