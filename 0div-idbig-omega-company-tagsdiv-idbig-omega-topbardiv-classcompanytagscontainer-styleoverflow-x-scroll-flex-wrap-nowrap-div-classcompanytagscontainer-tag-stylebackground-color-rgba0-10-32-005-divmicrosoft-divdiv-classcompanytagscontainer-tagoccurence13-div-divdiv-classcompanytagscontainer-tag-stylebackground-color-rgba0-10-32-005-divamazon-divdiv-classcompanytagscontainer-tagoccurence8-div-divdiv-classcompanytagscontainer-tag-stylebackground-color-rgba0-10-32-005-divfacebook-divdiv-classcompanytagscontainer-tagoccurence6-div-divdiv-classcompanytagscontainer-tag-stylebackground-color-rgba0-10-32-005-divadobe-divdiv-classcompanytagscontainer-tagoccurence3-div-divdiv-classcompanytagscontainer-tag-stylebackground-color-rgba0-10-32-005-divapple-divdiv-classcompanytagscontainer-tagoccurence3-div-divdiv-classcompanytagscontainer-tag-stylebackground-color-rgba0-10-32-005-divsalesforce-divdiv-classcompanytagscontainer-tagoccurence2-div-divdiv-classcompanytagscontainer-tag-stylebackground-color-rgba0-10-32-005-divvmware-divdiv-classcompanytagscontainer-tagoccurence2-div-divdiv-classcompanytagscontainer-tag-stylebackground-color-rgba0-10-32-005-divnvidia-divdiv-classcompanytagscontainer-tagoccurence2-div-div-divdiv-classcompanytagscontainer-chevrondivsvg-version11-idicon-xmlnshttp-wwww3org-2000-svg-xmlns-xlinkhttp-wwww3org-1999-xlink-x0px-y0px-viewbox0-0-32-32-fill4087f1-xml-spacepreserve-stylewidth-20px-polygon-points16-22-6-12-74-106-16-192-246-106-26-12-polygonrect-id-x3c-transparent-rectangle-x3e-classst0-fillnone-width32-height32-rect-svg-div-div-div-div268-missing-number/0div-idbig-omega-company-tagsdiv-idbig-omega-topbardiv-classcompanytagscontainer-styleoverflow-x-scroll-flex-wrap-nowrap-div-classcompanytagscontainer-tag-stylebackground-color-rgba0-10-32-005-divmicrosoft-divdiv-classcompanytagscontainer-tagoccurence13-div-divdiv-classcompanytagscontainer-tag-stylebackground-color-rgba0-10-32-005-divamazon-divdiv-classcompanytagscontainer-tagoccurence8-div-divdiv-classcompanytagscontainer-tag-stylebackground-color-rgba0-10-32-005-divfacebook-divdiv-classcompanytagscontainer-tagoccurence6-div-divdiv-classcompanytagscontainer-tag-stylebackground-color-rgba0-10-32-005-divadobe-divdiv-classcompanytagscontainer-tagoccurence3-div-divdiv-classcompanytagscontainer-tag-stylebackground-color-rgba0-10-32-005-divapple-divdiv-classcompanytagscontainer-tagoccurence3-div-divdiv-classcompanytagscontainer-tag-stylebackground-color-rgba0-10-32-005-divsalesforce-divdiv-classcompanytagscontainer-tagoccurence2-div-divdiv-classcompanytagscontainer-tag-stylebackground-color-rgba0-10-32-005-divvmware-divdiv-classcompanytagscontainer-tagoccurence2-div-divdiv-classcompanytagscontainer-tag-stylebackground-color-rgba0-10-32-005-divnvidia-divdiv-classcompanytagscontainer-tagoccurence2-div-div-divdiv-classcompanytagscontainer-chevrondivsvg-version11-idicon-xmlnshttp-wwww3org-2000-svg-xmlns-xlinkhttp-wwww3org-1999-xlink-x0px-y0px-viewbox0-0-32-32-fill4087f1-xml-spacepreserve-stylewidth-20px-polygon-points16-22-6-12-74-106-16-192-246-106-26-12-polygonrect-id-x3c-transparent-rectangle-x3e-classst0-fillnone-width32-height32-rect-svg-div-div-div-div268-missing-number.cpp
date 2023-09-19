class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int a=0,b=0;
        
        for(int i=0;i<nums.size();i++){
            a=a^i;
            b=b^nums[i];
        }
        a=a^nums.size();
        
        return a^b;
    }
};