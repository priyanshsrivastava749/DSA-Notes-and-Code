//the following code contain the solution of leetcode problem 102 using DFS technique...https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
  public:
      int level(TreeNode* root){
          if(root == NULL)return 0;
          return 1 + max(level(root->right),level(root->left));
      }
      void nth_level(TreeNode* root,int lvl,int t_lvl,vector<int>&v){
          if(root == NULL)return;
          if(lvl == t_lvl){
              v.push_back(root->val);
              return;
          }
          nth_level(root->left,lvl+1,t_lvl,v);
          nth_level(root->right,lvl+1,t_lvl,v);
      }
      void lOrder(TreeNode* root,vector<vector<int>>&ans){
          int n = level(root);
          for(int i=0;i<n;i++){
              vector<int> v;
              nth_level(root,0,i,v);
              ans.push_back(v);
          }
      }
      vector<vector<int>> levelOrder(TreeNode* root){
          vector<vector<int>> ans;
          lOrder(root,ans);
          return ans;
      }
  };