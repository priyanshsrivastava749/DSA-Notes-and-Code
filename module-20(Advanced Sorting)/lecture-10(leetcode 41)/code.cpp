class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        while(i < n){
            if(arr[i]<=0) i++;
            // int correct_idx = arr[i] - 1;
            else if((arr[i] - 1) >= n || arr[i] == i+1 || arr[i] == arr[arr[i] - 1]) i++;
            else swap(arr[i],arr[arr[i]-1]);
        }
        for(int i=0;i<n;i++){
            if(arr[i] != i+1)return i+1;
        }
        return n+1;
    }
};