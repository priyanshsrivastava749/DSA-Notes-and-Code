#include<iostream>
#include<queue>
using namespace std;
class Node{
  public:
  int val;
  Node* right;
  Node* left;
  Node(int val){
    this->val = val;
    right = NULL;
    left = NULL;
  }
};
int size_of_tree(Node* root){
  if(root == NULL)return 0;
  else return 1 + size_of_tree(root->left) + size_of_tree(root->right); 
}
bool isCBT(Node* root){
  int size = size_of_tree(root);
  queue<Node*> q;
  q.push(root);
  int count = 0;
  while(count < size){
    Node* temp = q.front();
    count++;
    q.pop();
    if(temp!=NULL){
    q.push(temp->left);
    q.push(temp->right);
  }
}
  while(!q.empty()){
    Node* temp = q.front();
    if(temp != NULL)return false;
    q.pop();
  }
  return true;
}
bool Max_heap_property(Node* root){
  if(root == NULL)return true;
  else if(root->left != NULL && (root->val < root->left->val)){
    return false;
  }
  else if(root->right != NULL && (root->val <root->right->val)){
    return false;
  }
  else return Max_heap_property(root->left) && Max_heap_property(root->right);
}
bool is_max_heap(Node* root){
  return Max_heap_property(root) && isCBT(root);
}
int main(){
    Node* root = new Node(100);
    root->left = new Node(90);
    root->right = new Node(80);
    root->left->left = new Node(70);
    root->left->right = new Node(60);
    root->right->left = new Node(50);
    root->right->right = new Node(40);
    root->left->left->left = new Node(30);

    cout << "isCBT: " << isCBT(root) << endl;
    cout << "Max Heap Property: " << Max_heap_property(root) << endl;
    cout << "Is Max Heap: " << is_max_heap(root) << endl;

  return 0;
 
}