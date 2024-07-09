class Solution {
    public int subtractProductAndSum(int n) {
        
        int product=1;
        int sum=0;
        
        int t=n;
        while(t>0){
            
            sum+=(t%10);
            product*=(t%10);
            
            t=t/10;
        }
        
        return product-sum;
    }
}