//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int[] ans = new Solve().findTwoElement(a, n);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solve {
    int[] findTwoElement(int arr[], int n) {
        // code here

       HashMap<Integer,Integer> mp = new HashMap<>();
       
       long sum = 0;
       long expected = (long)n*(n+1)/2;
       long repeating = 0;
       
       for(int i=0;i<n;i++){
           sum += arr[i];
           
           if(mp.containsKey(arr[i])){
               repeating = arr[i];
           }else{
               mp.put(arr[i],1);
           }
       }
       
       int missing = (int)(expected-(sum-repeating));
       
       return new int[]{(int)repeating,missing};
       
    }
}