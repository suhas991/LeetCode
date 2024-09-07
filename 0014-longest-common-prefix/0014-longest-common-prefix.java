class Solution {
    public String longestCommonPrefix(String[] strs) {
        
        Arrays.sort(strs);
        
        String first = strs[0];
        String last = strs[strs.length-1];
        
        String res="";
        
        int i=0;
        while(i < Math.min(first.length(),last.length())){
            if(first.charAt(i) == last.charAt(i)){
                res += first.charAt(i);
            }else{
                break;
            }
            i++;
        }
        
        return res;
    }
}