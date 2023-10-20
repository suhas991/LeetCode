class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        vector<int> ans(nums.begin(),nums.end());
        int count=0;
        
        for(int i=0;i<ans.size();i++){
           if(ans[i]!=val){
               nums[count++]=ans[i];
           } 
        }
        
        return count;
    }
};