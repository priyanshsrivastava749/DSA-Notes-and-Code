#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>v;
    vector<int>v1;
   

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int>v2;
    v2.push_back(4);
    v2.push_back(5);


    vector<int>v3;
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);


    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);


    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    v[0][0] = 10; // Changing the first element of the first vector
    cout << "After modification:" << endl;  
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] % 2 == 0) {
                cout << "Even number found: " << v[i][j] <<"at  "<<i<<" , "<<j<< endl;
            } else {
                cout << "Odd number found: " << v[i][j] << endl;
            }
        }
    }
}