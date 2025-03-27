#include<iostream>
#include<climits>
#include<vector>
#include<stack>
#include <algorithm>
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
void post_iterative(node* root){
  vector<int>ans;
  stack<node*>st;
  if(root) st.push(root);
  while(st.size()>0){
    node* temp = st.top();
    st.pop();
    ans.push_back(temp->val);
    if(temp->left)st.push(temp->left);
    if(temp->right)st.push(temp->right);
  }
  reverse(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
}
void in_order_traversal(node* root){
  stack<node*> st;
  node* n = root;
  while(st.size()>0 || n){
    if(n!=NULL){
      st.push(n);
      n = n -> left;
    }
    else{
      node* temp = st.top();
      st.pop();
      cout<<temp->val<<" ";
      n = temp -> right;
    }
  }
}
void displayTree(node* root){
  if(root == NULL)return;
  cout<<root->val<<" ";
  displayTree(root->left);
  displayTree(root->right);
}

int main(){
  node* a = new node(1);
  node* b = new node(2);
  node* c = new node(3);
  node* d = new node(4);
  node* e = new node(5);
  node* f = new node(6);
  node* g = new node(7);
  a->left = b;
  a->right = c;
  b->right = e;
  b->left = d;
  c->right = g;
  c->left = f;
  post_iterative(a);
  cout<<endl;
  in_order_traversal(a);

  
  return 0;
}