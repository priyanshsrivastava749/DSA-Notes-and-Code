#include<iostream>
#include <climits>
#include<stack>
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
void pre_iterative(node* root){
  stack<node*> st;
  st.push(root);
  while(st.size()>0){
    node* temp = st.top();
    st.pop();
    cout<<temp->val<<" ";
    if(temp->right) st.push(temp->right);
    if(temp->left) st.push(temp->left);
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
  pre_iterative(a);
  
  return 0;
}