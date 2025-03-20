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
int level(node* root){
  if(root == NULL) return 0;
  return 1 + max(level(root->left),level(root->right));
}
void nth_level_display(node* root,int lvl,int t_lvl){
  if(root == NULL) return;
  if(lvl == t_lvl){
    cout<<root->val<<" ";
    return;
  }
  nth_level_display(root->left,lvl+1,t_lvl);
  nth_level_display(root->right,lvl+1,t_lvl);
}

void level_wise_display(node* root){
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
  level_wise_display(a);
 
  return 0;
}