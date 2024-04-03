class Solution {
public:
    string formword(string str){
        string res="";
        int i=0;
        while(str[i]!='\0'){
            res+=str[i];
            i++;
        }
        return res;
    }
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string str1="";
        string str2="";
        
        for(int i=0;i<word1.size() ;i++){
            str1+=formword(word1[i]);
            //cout<<str1<<endl;
        } 
        
        for(int i=0;i<word2.size() ;i++){
            str2+=formword(word2[i]);
            //cout<<str2<<endl;
        } 
        
        return (str1==str2)? true: false;
    }
};