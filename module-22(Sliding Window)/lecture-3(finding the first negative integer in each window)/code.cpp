#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[] = {2,-3,4,4,-7,-1,4,-2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int p = -1;
    for(int i=0;i<k;i++){
        if(arr[i] < 0) p = i;// p is holding the index having the first negative number in the array...
    }
    vector<int> ans(n,0);
    int i = 1;
    int j = i + k - 1;
    ans[0] = arr[p];
    while(j < n){
        if(p >= i)ans[i] = arr[p];
        else{
            for(int x=i; x<j; x++){
                if(arr[x] < 0){
                    p = x;
                }
                ans[i] = arr[p];
            }
        }
        i++;
        j++;
    }
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}