class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=arr.size()-1;i>=2;i--){
            int l=0,r=i-1;
            while(l<r){
                if(arr[l]+arr[r]>arr[i]){
                    count+=r-l;
                    r--;
                }else{
                    l++;
                }
            }
        }
        return count;
    }
};