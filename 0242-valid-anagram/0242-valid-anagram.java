class Solution {
    public boolean isAnagram(String s, String t) {
        
        if(s.length()!=t.length()){
            return false;
        }
        
        HashMap<Character,Integer> mp = new HashMap<>();
        
        for(int i=0;i<s.length();i++){
            mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)+1);
            mp.put(t.charAt(i),mp.getOrDefault(t.charAt(i),0)-1);
        }
        
        for(Character key:mp.keySet()){
            if(mp.get(key)!=0){
                return false;
            }
        }
        
        return true;
        
        
    }
}