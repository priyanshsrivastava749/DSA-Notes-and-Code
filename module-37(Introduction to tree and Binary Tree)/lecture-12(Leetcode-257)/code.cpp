//the following code contain the solution of the leetcode problem no 257 https://leetcode.com/problems/binary-tree-paths/
class Solution {
  public:
      void helper(TreeNode* root,string s,vector<string>&ans){
          if(root == NULL)return;
          string a = to_string(root->val);
          if(root->right == NULL && root->left == NULL){
              s += a;
              ans.push_back(s);
              return;
          }
          helper(root->left,s+a+"->",ans);
          helper(root->right,s+a+"->",ans);
      }
      vector<string> binaryTreePaths(TreeNode* root) {
          vector <string> ans;
          helper(root,"",ans);
          return ans;
      }
  };