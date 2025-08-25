class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
     int n = arr.size();
     vector<int> suffix(n,1);
     vector<int> prefix(n,1);
     for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] * arr[i-1];
     }
     for(int i=n-2; i>=0; i--){
        suffix[i] = arr[i+1] * suffix[i+1];
     }
     //now time to finally modify the array
     for(int i=0;i<n;i++){
        arr[i] = prefix[i] * suffix[i];
     }
     return arr;
    }    
};