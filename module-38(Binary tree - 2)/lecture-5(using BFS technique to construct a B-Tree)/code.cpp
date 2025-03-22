#include<iostream>
#include<climits>
#include<queue>
using namespace std;
class node{
  public:
  int val;
  node* right;
  node* left;
  node(int val){
    this->val = val;
    right = NULL;
    left = NULL;
  }
};
node* binary_tree(int arr[],int n){
  node* root = new node(arr[0]);
  int i = 1;
  int j = 2;
  queue<node*>q;
  q.push(root);
  while(q.size()>0 && i<n){
    node* temp = q.front();
    q.pop();
    node* l;
    node* r;
    if(arr[i] != INT_MIN) l = new node(arr[i]);
    else  l = NULL;
    if(j<n && arr[j] != INT_MIN) r = new node(arr[j]);
    else  r = NULL;
    temp -> left = l;
    temp -> right = r;
    if(l)q.push(l);
    if(r)q.push(r);
    i += 2;
    j += 2;
  }
  return root;
}
void level_wise_display(node* root){
  if(root == NULL) return;
  queue<node*>q;
  q.push(root);
  while(q.size()>0){
    node* temp = q.front();
    q.pop();
    cout<<temp->val<<" ";
    if(temp->left != NULL) q.push(temp->left);
    if(temp->right != NULL) q.push(temp->right);
  }
}
int main(){
  int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,7,8,9,INT_MIN};
  int n = sizeof(arr)/sizeof(arr[0]);
  node* a = binary_tree(arr,n);  
  level_wise_display(a);
 
  return 0;
}