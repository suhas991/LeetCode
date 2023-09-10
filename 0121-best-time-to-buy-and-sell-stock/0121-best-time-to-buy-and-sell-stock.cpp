class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy=prices[0];
        // int sell=0;
        
        int mprof=0;
        int cprof=0;
        
        for(int i=1;i<prices.size();i++){
            
            if(prices[i]-buy < 0){
                buy=prices[i];
            }else if(prices[i]-buy > cprof){
                cprof=prices[i]-buy;
            }
            
            mprof=max(mprof,cprof);
        }
        
        return mprof;
        
    }
};