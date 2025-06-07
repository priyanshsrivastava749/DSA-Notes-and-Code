class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int m = matrix.size();
        int n = matrix[0].size();
       
        int minc = 0, maxc = n - 1;
        int minr = 0, maxr = m - 1;
        vector<int> v;

        while (minc <= maxc && minr <= maxr) {
            // right
            for (int j = minc; j <= maxc; j++)
                v.push_back(matrix[minr][j]);
            minr++;

            // down
            for (int i = minr; i <= maxr; i++)
                v.push_back(matrix[i][maxc]);
            maxc--;

            // left
            if (minr <= maxr) {
                for (int j = maxc; j >= minc; j--)
                    v.push_back(matrix[maxr][j]);
                maxr--;
            }

            // up
            if (minc <= maxc) {
                for (int i = maxr; i >= minr; i--)
                    v.push_back(matrix[i][minc]);
                minc++;
            }
        }

        return v;
    }
};
