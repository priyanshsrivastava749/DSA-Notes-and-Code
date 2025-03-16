#include<iostream>
#include <climits>
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
int TreeSize(node* root){
  if(root == NULL)return 0;
  return 1 + TreeSize(root->left) + TreeSize(root->right);
}
int sumTree(node* root){
  if(root == NULL) return 0;
  return root->val + sumTree(root->left) + sumTree(root->right);
}
int max_in_tree(node* root){
  if(root == NULL)return INT_MIN;
  return max(root->val,max(max_in_tree(root->left),max_in_tree(root->right)));
}
int level_of_tree(node* root){
  if(root == NULL)return 0;
  return 1 + max(level_of_tree(root->right),level_of_tree(root->left));
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
  displayTree(a);
  cout<<endl;
  cout<<"The sum of elements of Tree: "<<sumTree(a);
  cout<<endl;
  cout<<"The size of Tree: "<<TreeSize(a);
  cout<<endl;
  cout<<"The max element of Tree: "<<max_in_tree(a)<<endl;
  cout<<"The level of tree is: "<<level_of_tree(a)<<endl;
  return 0;
}