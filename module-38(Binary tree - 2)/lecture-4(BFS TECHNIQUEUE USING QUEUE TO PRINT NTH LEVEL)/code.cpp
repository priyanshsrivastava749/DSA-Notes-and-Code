#include<iostream>
#include <climits>
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
int level(node* root){
  if(root == NULL) return 0;
  return 1 + max(level(root->left),level(root->right));
};
void level_wise_display(node* root,queue<node*>&q){
  if(root == NULL) return;
  q.push(root);
  while(q.size()>0){
    node* temp = q.front();
    q.pop();
    cout<<temp->val<<" ";
    if(temp->left != NULL) q.push(temp->left);
    if(temp->right != NULL) q.push(temp->right);
  }
};


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
  queue<node*> q;
  level_wise_display(a,q);
 
  return 0;
}