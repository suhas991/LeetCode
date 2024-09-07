class Solution {
    public String removeOuterParentheses(String s) {
       
       if(s.length() == 0) return "";
        
       int ptr=0;
        String res="";
        
        for(int i=0;i<s.length();i++){
            
            if(s.charAt(i)=='('){
                if(ptr != 0){
                    res += s.charAt(i);
                }
                ptr++;
            }else if(s.charAt(i) == ')'){
                ptr--;
                if(ptr!=0){
                    res += s.charAt(i);
                }
                
            }
            
        }
        
        return res;
    }
}