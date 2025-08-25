class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.length();
        vector<int>pre(n+1);
        vector<int>suff(n+1);
        //filling the pre array
        int p_n = 0;
        for(int i=0; i<n+1; i++){
            pre[i] = p_n;
            if(i<n && c[i]=='N')p_n++;
        }
        //filling the suff array
        int s_y = 0;
        for(int i=n; i>=0; i--){
            if(i<n && c[i]=='Y')s_y++;
            suff[i] = s_y;
        }
        int mn = INT_MAX;
        int min_dex = -1;
        for(int i=0;i<n+1;i++){
            int penalty = suff[i] + pre[i];
            if(mn > penalty){
                mn = penalty;
                min_dex = i;
            }
        }
     return min_dex;
    }
};