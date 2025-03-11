//the following code contains the solution of the problem statement that is asking to find the first -ve number of the window of size k that is sliding through an array//
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> near_next_negative(vector<int> &v,int k){
  int n = v.size();
  queue<int>q;
  int i = 0;
  while(i<=v.size()-1){
    if(v[i]<0){
      q.push(i);
      i++;
    }
    else i++;
  }
  // for(int i=1;i<=q.size();i++){
  //   int x = q.front();
  //   q.pop();
  //   cout<<x<<" ";
  //   q.push(x);
  // }
  // cout<<endl;
  //now we are supposing that the queue has got all its indexes with negative value
  vector<int> ans;
  for(int i=0;i<=n-k;i++){
    while(q.size()>0 && q.front()<i){
      q.pop();
    }
    if(q.front()>=i && q.front()<i+k){
      ans.push_back(v[q.front()]);
    }
    else if(q.front()>i+k-1){
      //means current wale window k saare element me se koi bhi negative nahi hai aur negative aage aane wale index per hai
      ans.push_back(0);
    }
  }
  return ans;
}
int main(){
  vector<int> v;
  int n;
  cout<<"Enter the number of elements in the vector: ";
  cin>>n;
  for(int i=0;i<=n-1;i++){
    int temp;
    cin>>temp;
    v.push_back(temp);
  }
  vector<int> ans = near_next_negative(v,3);
  for(int i=0;i<=ans.size()-1;i++){
    cout<<ans[i]<<" ";
  }
return 0;
}

