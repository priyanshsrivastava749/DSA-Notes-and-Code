#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of rows:";
    cin>>n;
    int c=1;   // Creation of a variabe for the value increment in loop everytime the loop proceeds .
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<c++ <<" ";
        }
        cout<<endl;
    }
}

// op-
// Enter the number of rows:5
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15 
