#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Total lines:";
    cin>>n;
   int nsp=n-1;                     //nsp or number of spaces in a line (which is followed by the loop iterator "i"
   int nst=1;                       //nst or the number of stars in a line
   for(int i=1;i<=2*n-1;i++){       // for the line changing (we'll have 2*n-1 lines so this for loop is executed till 2(n)-1
    for(int j=1;j<nsp;j++){         //For spaces;
        cout<<" ";
    }
    if(i<=n-1)  nsp--;              // if i < n-1 , value of nsp will decrease by 1
    else nsp++;                     // if i>= n-1 , value of nsp will increase by 1

    for(int k=1;k<=nst;k++){        //For stars
        cout<<"*"<<"";
    }
    if(i<=n-1) nst+=2;               // if i < n-1 , value of nst will decrease by 1
    
    else nst-=2;                     // if i>= n-1 , value of nst will increase by 1
    cout<<endl;
   }

}

// op-
// Total lines:5
//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *
