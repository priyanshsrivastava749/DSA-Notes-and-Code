#include<iostream>
#include<vector>
using namespace std;
void change2Dvector(vector<vector<int>>&v) {// & is used to pass the vector by reference because without it , the function would misinterpret and create another copy of vector witht the same name which causes conflicts 
 
    v[0][0] = 10; 
}
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

    change2Dvector(v); // Calling the function to change the first element of the first vector
    cout << "After modification:" << endl;  
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
//advantages of using vector over array:
// 1. Dynamic Size: Vectors can grow and shrink in size dynamically, while arrays have a fixed size.
// 2. Memory Management: Vectors handle memory allocation and deallocation automatically, reducing the risk of memory leaks.
// 3. Built-in Functions: Vectors provide many built-in functions for easy manipulation, such as push_back, pop_back, and insert.
// 4. Type Safety: Vectors are type-safe, meaning they can only store elements of a specific type, reducing runtime errors.
// 5. Iterators: Vectors support iterators, allowing for easy traversal and manipulation of elements.

