#include<iostream>
#include<vector>
using namespace std;

int main(){
    int numrows = 5;
    vector<vector<int>> v;

    for(int i = 0; i < numrows; i++){
        vector<int> a(i + 1); // +1 to allow access to index i
        v.push_back(a);
    }

    for(int i = 0; i < numrows; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                v[i][j] = 1;
            } else {
                v[i][j] = v[i-1][j] + v[i-1][j-1];
            }
        }
    }

    // Displaying Pascal's Triangle
    for(int i = 0; i < numrows; i++){
        for(int j = 0; j <= i; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}