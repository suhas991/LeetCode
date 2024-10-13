class Solution {
    public int maxArea(int[] height) {
    
      int start=0,end=height.length-1;
      int maxRes=0;
      
        while(start<end){
            
            
            int res = (end-start) * Math.min(height[end],height[start]);
            // height * length 
            maxRes = Math.max(maxRes,res);
            
            //System.out.println(start+" "+end+" "+res+" "+maxRes);
            
            if(height[start] < height[end]){
                start++;
            }else{
                end--;
            }
            
            
        }
        
      return maxRes;
    }
}