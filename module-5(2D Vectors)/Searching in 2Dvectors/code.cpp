#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Start from the top right
        //bada hai toh left jao 
        //chota hai toh neeche jao
        int rows=matrix.size();
        int cols=matrix[0].size();
        int i=0;
        int j=cols-1;
        while(i<=rows-1 && j>=0){
            if(matrix[i][j]==target) return matrix[i][j];
            else if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};