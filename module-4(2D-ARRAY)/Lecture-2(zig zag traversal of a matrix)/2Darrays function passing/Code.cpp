#include<iostream>
#include<vector>
using namespace std;
void change2d(int arr[3][3]){ // here , we have to pass the array size too if we're working with 2d arrays
    // This function modifies the first element of the 2D array
 
    arr[0][0] = 10; // Changing the first element of the first vector
   
}
int main(){
 int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // here, we have to define the column size of the array  needlessness as we are using 2d arrays , its imp. to set the column size
 cout << "Before modification:"<<arr[0][0]<< endl;
  // Changing the first element of the first vector
 change2d(arr);
    cout << "After modification:" << endl;
    cout<< arr[0][0] << endl; // Output the modified first element
}