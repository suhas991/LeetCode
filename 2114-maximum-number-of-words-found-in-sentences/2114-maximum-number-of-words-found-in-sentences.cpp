class Solution {
public:
    int checkword(string word){
        int c=0;
        int i=0;
        while(word[i]!='\0'){
            if(word[i]==' ')
                c++;
            i++;  
        }
        return c+1;
    }
    
    int mostWordsFound(vector<string>& sentences) {
        int count=0;
        
        for(int i=0;i<sentences.size();i++){
            
            count = max(count,checkword(sentences[i]));
        }
        
        return count;
    }
};