class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& nums) {
        
        int count=0;
        
        for(int i=0;i<nums.size();i++){
           for(int j=0;j<nums.size();j++){
               
               reverse(nums[j].begin(),nums[j].end());
               //cout<<nums[i]<<" "<<nums[j]<<endl;
               if(i<j && nums[i] == nums[j])
               count++;
               reverse(nums[j].begin(),nums[j].end());
               }
               
        }
        return count;
    }
};