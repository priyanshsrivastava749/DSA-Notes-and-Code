class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxidx = 0;
        int sum = 0;
        int maxsum = INT_MIN;
        for(int i=0; i<minutes; i++){
            sum += customers[i] * grumpy[i];
        }
        int i = 1;
        maxsum = sum;
        int j = i + minutes - 1;
        while(j < n){
            sum = sum + (customers[j] * grumpy[j]) - (customers[i-1] * grumpy[i-1]);
            if(maxsum < sum){
                maxsum = sum;
                maxidx = i;
            }
            i++;
            j++;
        }
        for(int i = maxidx; i < maxidx + minutes; i++){
            grumpy[i] = 0;
        }
        int anssum = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 0){
                anssum += customers[i];
            }
        }
        return anssum;
    }
};