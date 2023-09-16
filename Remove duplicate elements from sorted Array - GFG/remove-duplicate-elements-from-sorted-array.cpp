//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int A[],int N){
        // code here
        
         if(N == 0 || N == 1) return N;
        // Approach 2: O(n) time and Theta(1) space;
        
        
        int j=1;
        for(int i=0;i<N-1;i++){
            if(A[i]!=A[i+1]){
                A[j++]=A[i+1];
            }
        }
        return j;
    } 
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends