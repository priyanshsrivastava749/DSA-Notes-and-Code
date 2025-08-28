class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<int>suff(n,0);
        suff[n-1] = satisfaction[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i] = satisfaction[i] + suff[i+1]; 
        }
        int idx = -1;
        for(int i=0; i<n; i++){
            if(suff[i]>=0){
                idx = i;
                break;
            }
        }
        if(idx == -1) return 0;
        int max_sum=0;
        int x=1;
        for(int i=idx; i<n; i++){
            max_sum += satisfaction[i]*x;
            x++;
        }
        return max_sum;
    }
};