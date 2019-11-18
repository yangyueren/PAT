public class binarySearch {
    public static void main(String[] args) {
        int[] a = {0,1,2,4,5,7,8};
        //如果是查找，传入最大数组下标；如果是插入，传入下标➕1
        int t = binarySearch.binarysearch(a, 2, a.length-1);
        System.out.println(t);
    }

    //返回第一个大于等于target的位置
    // < 对于l=mid+1
    //传进来的n是最右侧下标
    static int binarysearch(int[] s, int target, int n){
        int l = 0;
        int r = n;
        while (l<r){
            int mid = l + (r-l)/2;
            if (s[mid] < target){
                l = mid+1;
            }else {
                r = mid;
            }
        }
        return l;
    }
    /*
    static int binarysearch(int[] s, int target, int n){
        int l = 0;
        int r = n;
        while (l < r){
            int mid = l + (r-l)/2;
            if (s[mid] < target){
                l = mid+1;
            }else {
                r = mid;
            }
        }
        return l;
    }
    */
    /*
    static int binarysearch(int[] s, int target, int n){
        int l = 0;
        int r = n;
        while (l < r){
            int mid = l + (r-l)/2;
            if (target <= s[mid]){
                r = mid;
            }else {
                l = mid+1;
            }
        }
        return l;
    }
    */
    /*
    static int binarysearch(int[] s, int target, int n){
        int i = 0;
        int j = n;

        while (i < j){
            int mid = i + (j-i)/2;
            if (s[mid] >= target){
                j = mid;
            }
            else {
                i = mid+1;
            }
        }
        return i;
    }
    */
    /*
    static int binarysearch(int[] s, int target, int n){
        int l = 0;
        int r = n;
        while (l < r){
            int mid = l + (r-l)/2;
            //mid 比target小，l = mid+1，保证了mid及以前的都不是所求解
            if (s[mid] < target){
                l = mid + 1;
            }
            //当s[mid]大于等于target
            //重要，r = mid，不能是mid-1，因为s[mid-1]可能小于target
            else {
                r = mid;
            }
        }
        return l;
    }
    */
}
