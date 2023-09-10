class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int j=0;
        int count=0;
        for(int i=0;haystack[i]!='\0';i++){
            
            int start=i;
            while(haystack[i]==needle[j] && i<haystack.length() && j<needle.length()){
                i++;
                j++;
                count++;
            }
            if(count==needle.length()){
                return i-needle.length();
            }
            if(count>0){
                count=0;
                i=start;
                j=0;
            }
            
        }
        return -1;
    }
};