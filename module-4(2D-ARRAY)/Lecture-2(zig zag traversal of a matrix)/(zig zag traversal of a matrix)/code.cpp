#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int m;
    cout<<"Enter the number of rows in matrix";
    cin>>m;
    int n;
    cout<<"Enter the number of columns in matrix";
    cin>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"The matrix is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int arr1[m][n];
    for(int i=0;i<m;i++){
        
        if(i%2==0){
             for(int j=n-1;j>=0;j--){
                cout<<arr[i][j]<<" ";
             
            }
        }
        else{
            for(int j=0;j<n;j++){
               cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;               
    }

}