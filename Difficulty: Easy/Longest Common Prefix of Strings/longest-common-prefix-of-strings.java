//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String arr[] = read.readLine().trim().split(" ");

            Solution ob = new Solution();
            System.out.println(ob.longestCommonPrefix(arr));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public String longestCommonPrefix(String arr[]) {
        // code here
        int n=arr.length;
        if(n == 0){
            return "-1";
        }
        
        if(n == 1){
            return arr[0];
        }
        
        Arrays.sort(arr);
        
        
        String first = arr[0],last =arr[n-1];
        int i=0;
        
        while((i<first.length() && i<last.length()) && first.charAt(i)==last.charAt(i)){
            i++;
        }
        
        String res = first.substring(0,i);
        
        if(res.isEmpty()){
            return "-1";
        }
        else{
            return res;
        }
        
        
    }
}

//User function template for C++

// class Solution{
//   public:
    
//     string longestCommonPrefix (string arr[], int N)
//     {
//         // your code here
//         if(N==0)
//         return "-1";
//         if(N==1)
//         return arr[0];
        
//         sort(arr,arr+N);
        
//         int en=min(arr[0].size(),arr[N-1].size());
        
//         string first=arr[0],last=arr[N-1];
//         int i=0;
//         while(i<en && first[i]==last[i]){
//             i++;
//         }
        
//         string pre=first.substr(0,i);
        
//         if(pre=="")
//         return "-1";
        
//         return pre;
//     }
// };