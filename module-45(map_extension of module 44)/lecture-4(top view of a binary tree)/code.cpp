#include<iostream>
#include<queue>
#include<unordered_map>
#include <climits>
using namespace std;
class TreeNode{
  public:
  int val;
  TreeNode* right;
  TreeNode* left;
  TreeNode(int val){
    this->val = val;
    right = NULL;
    left = NULL;
  }
};
void Top_View(TreeNode* root){
  unordered_map<int ,int> m;
  queue<pair<TreeNode*,int>> q;
  pair<TreeNode*,int> r;
  r.first = root;
  r.second = 0;//level of the root
  q.push(r);
  //lets initiate the bfs
  while(q.size()>0){
    TreeNode* temp = q.front().first;//this is the TreeNode 
    int temp_val = temp->val;
    int level = q.front().second;
    q.pop();
    if(m.find(level) == m.end()){
      m[level] = temp_val;
    }
    if(temp -> left != NULL){
      pair<TreeNode*,int> r;
      r.first = temp->left;
      r.second = level - 1;
      q.push(r);
    }
    if(temp -> right != NULL){
      pair<TreeNode*,int> r;
      r.first = temp->right;
      r.second = level + 1;
      q.push(r);
    }
  }
  int max_lvl = INT_MIN;
  int min_lvl = INT_MAX;
  for(auto x : m){
    max_lvl = max(x.first,max_lvl);
    min_lvl = min(x.first,min_lvl);
  }
  for(int i=min_lvl; i<=max_lvl; i++){
    cout<<m[i]<<" ";
  }
  cout<<endl;
}
int main(){
  TreeNode* a = new TreeNode(1);
  TreeNode* b = new TreeNode(2);
  TreeNode* c = new TreeNode(3);
  TreeNode* d = new TreeNode(4);
  TreeNode* e = new TreeNode(5);
  a -> left = b;
  a -> right = c;
  b -> left = d;
  b -> right = e;
  Top_View(a); 
  return 0;
}