class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        int i=0;
        while(s[i]!='\0'){
            if(isalnum(s[i])){
                ans += tolower(s[i]); 
            }
            i++;
        }
        string rev=ans;
        reverse(rev.begin(),rev.end());
        if(rev==ans)
            return 1;
        else
            return 0;
        
        
    }
};