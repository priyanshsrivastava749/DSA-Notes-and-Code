#include <iostream>
#include <vector>
using namespace std;
class Node{
  public:
  int val;
  Node* left;
  Node* right;
  Node(int val){
    this->val = val;
     left = NULL;
    right = NULL;
  }
};
void inorder(Node* root, vector<int>&arr){
  if(root == NULL)return;
  inorder(root->right,arr);
  arr.push_back(root->val);
  inorder(root->left,arr);
}
void preorder(Node* root,vector<int>&arr,int* i){
  if(root == NULL)return;
  root->val = arr[(*i)++];
  preorder(root->left,arr,i);
  preorder(root->right,arr,i);
}
int level(Node* root){
  if(root == NULL) return 0;
  return 1 + max(level(root->left),level(root->right));
}
void nth_level_display(Node* root,int lvl,int t_lvl){
  if(root == NULL) return;
  if(lvl == t_lvl){
    cout<<root->val<<" ";
    return;
  }
  nth_level_display(root->left,lvl+1,t_lvl);
  nth_level_display(root->right,lvl+1,t_lvl);
}
void level_wise_display(Node* root){
  int n = level(root);
  for(int i=0;i<n;i++){
    for(int j=n-1-i;j>0;j--){
      cout<<" ";
    }
    nth_level_display(root,0,i);
    cout<<endl;
  }
}
int main(){
  Node* a = new Node(10);
  Node* b = new Node(5);
  Node* c = new Node(16);
  Node* d = new Node(1);
  Node* e = new Node(8);
  Node* f = new Node(12);
  Node* g = new Node(20);
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  level_wise_display(a);
  vector<int>arr;
  inorder(a,arr);
  int i = 0;
  preorder(a,arr,&i);
  level_wise_display(a);
  return 0;
}