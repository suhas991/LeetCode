//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {

    // Function to reverse every sub-array group of size k.
    void reverseInGroups(ArrayList<Long> arr, int k) {
       int n= arr.size();
       
       k = k>n?n:k;
       
       int ptr=0;
       while(ptr<n){
           if(ptr+k-1>=n){
               reverse(ptr,n-1,arr);
           }else{
               reverse(ptr,ptr+k-1,arr);
           }
           ptr = ptr+k;;
       }
       
        
    }
    
     static void reverse(int start,int end,ArrayList<Long> arr){
        while(start<=end){
            long temp=arr.get(start);
            arr.set(start,arr.get(end));
            arr.set(end,temp);
            start++;
            end--;
        }
    }
}

//{ Driver Code Starts.

public class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // consume the newline
        while (t-- > 0) {
            int k = sc.nextInt();
            sc.nextLine(); // consume the newline
            String input = sc.nextLine();
            ArrayList<Long> arr = new ArrayList<>();
            Scanner ss = new Scanner(input);
            while (ss.hasNextLong()) {
                arr.add(ss.nextLong());
            }
            Solution ob = new Solution();
            ob.reverseInGroups(arr, k);
            for (long num : arr) {
                System.out.print(num + " ");
            }
            System.out.println();
        
System.out.println("~");
}
        sc.close();
    }
}
// } Driver Code Ends