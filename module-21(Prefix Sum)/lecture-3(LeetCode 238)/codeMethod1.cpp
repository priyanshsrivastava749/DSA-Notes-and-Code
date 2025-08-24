class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
      int product = 1;
      int n = arr.size();
      int p2 = 1;
      int noz = 0;
      for(int i=0; i<n; i++){
        //see what we've got is product is general product of all elements and p2 is avoiding the zeros getting multiplied
        if(arr[i] == 0)noz++;
        product *= arr[i];
        if(arr[i]!=0)p2*=arr[i];
      }
      if(noz>1)p2 = 0;
      for(int i=0;i<n;i++){
        if(arr[i] != 0)arr[i] = product / arr[i];
        else arr[i] = p2;
      }
    return arr;
    }
};