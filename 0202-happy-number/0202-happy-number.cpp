class Solution {
public:
    bool isHappy(int n) {
        
     
        set<int> sp;
        sp.insert(n);
        
        int next=0;
        
        while(1){
            int rem=0;
            while(n>0){
                rem=n%10;
                next=next+pow(rem,2);
                n=n/10;
            }
            if(next==1){
                return true;
            }
            if(sp.find(next)==sp.end()){
                sp.insert(next);
            }else{
                return false;
            }
            n=next;
            next=0;
        }
    }
};