//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
    vector<int> find3Numbers(vector<int> a, int n) {
        // Your code here
        vector<int> ans;
        if(a.size()<3){
            return ans;
        }
        
        int min=0;
	    int max=n-1;
	    
	    int smaller[n];
	    smaller[0]=-1;
	    for(int i=1;i<n;i++){
	        if(a[i]<=a[min]){
	            min=i;
	            smaller[i]=-1;
	        }else{
	            smaller[i]=min;
	        }
	    }
	    
	    int greater[n];
	    greater[n-1]=-1;
	    for(int i=n-2;i>=0;i--){
	        if(a[i]>=a[max]){
	            max=i;
	            greater[i]=-1;
	        }else{
	            greater[i]=max;
	        }
	    }
	
	    for(int i=0;i<n;i++){
	        
	        if(smaller[i]!=-1 && greater[i]!=-1){
	            ans.push_back(a[smaller[i]]);
	            ans.push_back(a[i]);
	            ans.push_back(a[greater[i]]);
	            break;
	        }
	    }
	    return ans;
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends