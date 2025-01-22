//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = inputLine.length;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            long ans = new Solution().maxProduct(arr);
            System.out.println(ans);
        
System.out.println("~");
}
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    long maxProduct(int[] arr) {
        // code here
        long flar=0;
        long slar=0;
        long tlar=0;
        
        long fmin=0;
        long smin=0;
        
        
        for(int i=0;i<arr.length;i++){
            
            if(arr[i]>flar){
                
                tlar=slar;
                slar=flar;
                flar=arr[i];
                
            }else if(arr[i]>slar){
                tlar= slar;
                slar = arr[i];
            }else if(arr[i] > tlar){
                tlar=arr[i];
            }
            
            //System.out.println(flar + " "+slar+" "+tlar);
            if(arr[i]<fmin){
                smin=fmin;
                fmin=arr[i];
            }else if(arr[i] > fmin && arr[i] <smin){
                smin=arr[i];
            }
            
        }
        
        
        return Math.max(fmin * smin * flar,
               flar * slar * tlar);
    }
}
