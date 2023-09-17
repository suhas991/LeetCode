//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<bits/stdc++.h>
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
         sort(arr,arr+n);
        set<int> s;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1]){
                s.insert(arr[i]);
                i++;
            }
        }
        vector<int> v(s.begin(),s.end());
        if(v.empty())
            return {-1};
        return v;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends