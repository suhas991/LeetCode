//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String s = read.readLine();

            Solution ob = new Solution();
            String result = ob.removeDups(s);

            System.out.println(result);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    String removeDups(String str) {
        // code here
      HashSet<Character> st = new HashSet<>();
      StringBuilder res = new StringBuilder();
      
      for(int i=0;i<str.length();i++){
          if(!st.contains(str.charAt(i))){
             res.append(str.charAt(i));  
          }
          st.add(str.charAt(i));
      }
      
      return res.toString();
    }
}