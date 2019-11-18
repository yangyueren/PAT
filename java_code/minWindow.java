public class minWindow {
    public static void main(String[] args) {
        minWindow p = new minWindow();
//        p.minCoverSubstring();
//        p.containArrangement();
//        p.countNoRepeatedChars();
        p.subarrayWithDistinctK();
    }

    /*
    * 查询字符串s = "jjdkksl"不重复字符的最大子串的长度
    * */
    public void countNoRepeatedChars(){
        String string = "jjklnwel";
        char[] s = string.toCharArray();
        int l = 0;
        int[] hash = new int[26];
        int max = 0;
        for (int r = 0; r < s.length; r++) {
            hash[s[r]-'a']++;
            //important 要判断hash[s[r]-'a']不等于1
            while (hash[s[r] - 'a'] != 1 ){
                hash[s[l]-'a']--;
                l++;
            }
            if (r-l+1>max){
                max = r-l+1;
                System.out.println(max);
            }

        }
    }
    /*
    * s1 contains the arrangement of s2
    * s1 = "ksjddkkrteks"
    * s2 = "ert"
    * 窗口大小是固定的，每次移动r，l也要加1*/
    public void containArrangement(){
        String s1s = "kdkslenf";
        String s2s = "enl";
        char[] s1 = s1s.toCharArray();
        char[] s2 = s2s.toCharArray();
        int count = s2.length;
        int[] hash = new int[26];
        int l = 0;
        String result = "";
        for (int i = 0; i < s2.length; i++) {
            hash[s2[i] - 'a'] += 1;
        }

        for (int r = 0; r < s1.length; r++) {
            hash[s1[r] - 'a'] -= 1;
            if (hash[s1[r] - 'a'] >= 0){
                count--;
            }
            while (l < r && hash[s1[l] - 'a'] < 0){
                hash[s1[l] - 'a']++;
                l++;
            }
            if (count == 0 && r - l + 1 == s2.length){
                result += s1s.substring(l, r+1);
                result += " ";
                System.out.println(result);
            }
        }
    }


    /*
    * s = "abcdefsd"
    * t = "dsf"
    * 返回s中包含t中所有字符的最小子串"defs
    * 当左边指向当不需要当字符时候，移动
    *   {1. 指向当字符不在s中，2. 指向的字符'f'虽然在s中，但是r已经包含进来另一个同样的字符'f'}
    *   */
    public void minCoverSubstring() {
        String s = "abcdefdssddf";
        String t = "ddf";
        String result = "";
        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();
        int[] hash = new int[256];
        for (int i = 0; i < t.length(); i++) {
            hash[tArr[i]]++;
        }
        int l=0, count=tArr.length, max = s.length()+1;
        for (int r = 0; r < sArr.length; r++) {
            hash[sArr[r]]--;
            if (hash[sArr[r]] >= 0){
                count--;
            }
            while (l < r && hash[sArr[l]] < 0){
                hash[sArr[l]]++;
                l++;
            }

            if (count == 0 && max > r-l+1){
                max = r-l + 1;
                result = s.substring(l, r+1);
                System.out.println(result);
//                result += s.substring(l, r+1);
            }

        }
//        System.out.println(result);
    }

    /*K个不同整数的子数组，好数组
    * */
    public void subarrayWithDistinctK(){
        int[] s = new int[]{1,2,1,2,3};
        int k = 2;
        int[] hash = new int[10];
        int l = 0;
        int count = 0;
        int results = 0;
        int result = 1;
        if (s == null || s.length < k){
            return;
        }
        for (int r = 0; r < s.length; r++) {
            hash[s[r]]++;
            if (hash[s[r]] == 1){
                count++;
            }
            //如果出现一个新的字符，result重置为1，l移动
            while (count > k && l < r){
                if (count > k) {
                    count--;
                    result = 1;
                }
                hash[s[l]]--;
                l++;
            }
            //如果没有新字符出现，当前result+1
            if (count == k){
                results += result;
                result++;
                System.out.println(results);
            }
        }

    }

    public void characterReplacement(){}

}



