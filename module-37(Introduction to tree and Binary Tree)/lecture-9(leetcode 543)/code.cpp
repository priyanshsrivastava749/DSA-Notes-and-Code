//the following code is the solution of a leetcode problem https://leetcode.com/problems/diameter-of-binary-tree/
class Solution {
  public:
      void helper(TreeNode* root,int* maxDeci){
          if(root == NULL)return;
          int Deci = level(root->right) + level(root->left);
          *maxDeci = max(*maxDeci,Deci);
          helper(root->left,maxDeci);
          helper(root->right,maxDeci);
      }
      int level(TreeNode* root){
          if(root == NULL)return 0;
          return 1 + max(level(root->right),level(root->left));
      }
      int diameterOfBinaryTree(TreeNode* root) {
          int maxDeci = 0;
          helper(root,&maxDeci);
          return maxDeci;
      }
  };