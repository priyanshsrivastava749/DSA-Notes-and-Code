// maximum sum subarray of size k
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int sum = 0;
    int k = 3; //size of the sliding window...
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<k; i++){
        sum += arr[i];
    }
    int i = 1;
    int j = i + k - 1;
    int maxsum = INT_MIN;
    int maxidx = -1;
    while(j < n){
        sum = sum - arr[i-1] + arr[j];
        if(maxsum<sum){
            maxsum = sum;
            maxidx = i;
        }
        i++;
        j++;
    }
    cout<<maxsum<<" "<<maxidx;
    return 0;
}
