class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> mp;
        
        for(int i=0;s[i]!='\0';i++){
            mp[s[i]]++;
        }
        
        for(int i=0;s[i]!='\0';i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};