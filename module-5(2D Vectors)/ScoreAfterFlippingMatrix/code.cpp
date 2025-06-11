#include <vector>
using namespace std;
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        //Making the first  of every row all 1's
        for(int i =0;i<rows;i++){
            if(grid[i][0]==0){
                for(int j=0;j<cols;j++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }
        //checking if in a column , noo is > than noz 
        // if noz>noo , flip
        //if noo>noz , let it be 
        for(int j=0;j<cols;j++){
            int noo=0;
            int noz=0;
            for(int i=0;i<rows;i++){
                if(grid[i][j]==0) noz++;
                else noo++;
            }
            if(noz>noo){
                for(int i=0;i<rows;i++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }
        int sum=0;
       
        for(int i =0;i<rows;i++){
             int x=1;
            for(int j=cols-1;j>=0;j--){
                   sum+=grid[i][j]*x;
                   x *=2;

            }
        }
        return sum;


    }
};// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid.
// Space Complexity: O(1), as we are not using any extra space that grows with input size.