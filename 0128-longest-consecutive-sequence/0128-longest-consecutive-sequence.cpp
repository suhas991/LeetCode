class Solution {
public:
    
    
    
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int longest=0;
        int cnt=1;
        int last_small=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]-1 == last_small){
                cnt++;
                last_small=nums[i];
            }else if(nums[i] !=last_small){
                cnt=1;
                last_small=nums[i];
            }
            
            longest=max(longest,cnt);
        }
        
        return longest;
    }
};