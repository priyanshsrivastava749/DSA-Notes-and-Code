class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int i = 0;
        int len = arr.size();
        while(i<len){
            int correct_index = arr[i];
            if(arr[i] == arr[correct_index]) return arr[i];
            else swap(arr[i],arr[correct_index]);
        }
        return 100;
    }
};