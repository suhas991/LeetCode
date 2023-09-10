class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int dp=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[dp]!=nums[i]){
                nums[++dp]=nums[i];
            }
        }
        dp++;
        
        return dp;
    }
};