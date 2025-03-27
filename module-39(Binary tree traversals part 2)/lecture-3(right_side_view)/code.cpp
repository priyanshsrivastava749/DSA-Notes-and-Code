// the following code contain the solution of leetcode problem: https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
  public:
      int level(TreeNode* root){
            if(root == NULL)return 0;
            return 1 + max(level(root->right),level(root->left));
        }
      void nth_level(TreeNode* root,int lvl,int t_lvl,vector<int>& ans){
            if(root == NULL)return;
            if(lvl == t_lvl){
                ans[lvl] = root->val;
                return;
            }
            nth_level(root->left,lvl+1,t_lvl,ans);
            nth_level(root->right,lvl+1,t_lvl,ans);
        }
      void lOrder(TreeNode* root,vector<int> &ans,int n){
            for(int i=0;i<n;i++){
               nth_level(root,0,i,ans);
            }
        }
      vector<int> rightSideView(TreeNode* root) {
          int n = level(root);
          vector<int> ans(n,0);
          lOrder(root,ans,n);
          return ans; 
      }
  };