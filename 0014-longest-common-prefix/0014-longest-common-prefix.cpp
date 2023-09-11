#include<bits/stdc++.h>

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        
        string ans="";
        
        sort(s.begin(),s.end());
        
        string f=s[0];
        string l=s[s.size()-1];
        
        int i=0;
        while(i<min(f.size(),l.size())){
            if(f[i]!=l[i]){
                return ans;
            }
            ans+=f[i];
            i++;
        }
        
        return ans;
    }
};