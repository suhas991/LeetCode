class Solution {
public:
    int count(int num){
        int rem=0;
        int sum=0;
        
        while(num>0){
            rem=num%10;
            sum+=rem;
            num/=10;
        }
        
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        
        int elesum=0;
        int digisum=0;
        
        for(int i=0;i<nums.size();i++){
            
            elesum +=nums[i];
            
            digisum += (nums[i]>9)?count(nums[i]):nums[i];
        }
        
        return abs(elesum-digisum);
    }
};