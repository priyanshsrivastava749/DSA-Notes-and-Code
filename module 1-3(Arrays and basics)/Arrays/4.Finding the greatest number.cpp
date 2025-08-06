
    #include<iostream>
    #include<limits>
using namespace std;
int main(){
    int size;
    cout<<"The size of the array is:";
    cin>>size;
    int arr[size];
    int max=INT16_MIN;
    cout<<"\n";
    cout<<"The elements of the array are:"<<endl;
    for(int i =0;i<size;i++){
        cin>>arr[i];
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"\n";
    cout<<max<<endl;
    cout<<"\n";
}
