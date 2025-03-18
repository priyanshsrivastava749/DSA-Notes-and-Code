//solution to leetcode problem number 226 https://leetcode.com/problems/invert-binary-tree/
class Solution {
  public:
      void helper(TreeNode* root){
          if(root == NULL) return;
          TreeNode* temp = root->right;
          root->right = root->left;
          root->left = temp;
          helper(root -> right);
          helper(root -> left);
      }
      TreeNode* invertTree(TreeNode* root) {
          helper(root);
          return root;
      }
  };