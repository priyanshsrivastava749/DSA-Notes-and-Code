//the following code snippet contain the solution for the leetcode problem 113 https://leetcode.com/problems/path-sum-ii/
class Solution {
  public:
      void helper(TreeNode* root,int targetSum,vector<vector<int>> &ans,vector<int> v){
          if (root == NULL)return;
          if(root->left == NULL && root->right == NULL){
              if(targetSum == root->val){
                  v.push_back(root->val);
                  ans.push_back(v);
              }
              return;
          }
          v.push_back(root->val);
          helper(root->left,targetSum-(root->val),ans,v);
          helper(root->right,targetSum-(root->val),ans,v);
      }
      vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          vector<vector<int>> ans;
          vector<int> v;
          helper(root,targetSum,ans,v);
          return ans;
      }
  };