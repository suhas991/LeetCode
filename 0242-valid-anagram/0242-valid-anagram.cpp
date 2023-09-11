class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.length();i++){
           mp[s[i]]++;
           mp[t[i]]--;
        }
        
        for(int i=0;i<mp.size();i++){
            if(mp[s[i]]!=0)
                return false;
        }
        return true;
        
    }
};