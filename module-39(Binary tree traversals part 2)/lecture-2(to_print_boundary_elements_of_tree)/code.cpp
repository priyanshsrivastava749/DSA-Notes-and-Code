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
    nth_level_display(root,0,i);
    cout<<endl;
  }
}
void left_boundry(node* root){
  if(root == NULL || (root->left == NULL && root->right == NULL))return;
  cout<<root->val<<" ";
  if(root->left)left_boundry(root->left);
  else left_boundry(root->right);
}
void right_boundry(node* root){
  if(root == NULL || (root->left == NULL && root->right == NULL))return;
  if(root->right)left_boundry(root->right);
  else left_boundry(root->left);
  cout<<root->val<<" ";
}
void leaf_node(node* root){
  if(root == NULL)return;
  if(root->left == NULL && root->right == NULL){
  cout<<root->val<<" ";
  return;
  }
  leaf_node(root->left);
  leaf_node(root->right);
}

int main(){
int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8};
int n = sizeof(arr) / sizeof(arr[0]);  
node* a = binary_tree(arr,n);
level_wise_display(a);
cout << endl;
left_boundry(a);
leaf_node(a);
right_boundry(a->right);
return 0;
}