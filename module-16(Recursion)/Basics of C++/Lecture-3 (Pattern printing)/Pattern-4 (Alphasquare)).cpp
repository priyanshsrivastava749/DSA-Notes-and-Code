#include<iostream>
using namespace std;
int main(){
    int n= char(n);
    cout<<" Enter the number of rows: " ;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<< (char)(j+64)<<" "; //typecasting is used in order to convert the integer value to character
        }
        cout<<endl;
    }
}

// op-
// Enter the number of rows:5
// A B C D E 
// A B C D E
// A B C D E
// A B C D E
// A B C D E
