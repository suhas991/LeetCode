class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
      
        string inc="X++";
        string pinc="++X";
        string dec="X--";
        string pdec="--X";
        
        int value=0;
        for(int i=0;i<operations.size();i++){
           if(operations[i].compare(inc) == 0 ||operations[i].compare(pinc)== 0){
               value++;
               //cout<<"INC";
           }else if(operations[i].compare(dec)== 0 || operations[i].compare(pdec)== 0){
               value--;
               //cout<<"DEC";
           }
        }
        
        return value;
    }
};