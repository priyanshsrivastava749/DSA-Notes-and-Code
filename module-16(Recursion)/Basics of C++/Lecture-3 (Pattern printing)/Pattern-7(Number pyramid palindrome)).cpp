#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the number of rows: ";
cin>>n; 
for(int i=1;i<=n;i++){
    
    for(int k=1;k<=n-i;k++){  // for spaces
        cout<<" ";
    }
   for(int j=1;j<=i;j++) 
        cout<<j;
    
     for(int k=i-1;k>=1;k--) //for the reverse order of the numbers   
             cout<<k;
cout<<endl;

 }
}


// op-
// Enter the number of rows: 5
//     1
//    121
//   12321
//  1234321
// 123454321
