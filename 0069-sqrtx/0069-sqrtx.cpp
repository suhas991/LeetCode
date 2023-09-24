class Solution {
public:
    int mySqrt(int x) {
        long long low=0;
        long long high=x;
        
        while(low<=high){
           long long mid=(low+high)/2;
           
            if(mid*mid == x){
                return mid;
            }else if(mid*mid < x){
                low=mid+1;
                
            }else{
                
                high=mid-1;
            }
            
        }
        //cout<<ans<<" "<<low<<" "<<high<<endl;
        return high;
    }
};