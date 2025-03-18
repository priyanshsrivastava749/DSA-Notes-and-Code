//the following code contain the solution for the leetcode problem 236
class Solution {
  public:
      bool exists(TreeNode* root,TreeNode* t){
          if(root == NULL)return false;
          if(root == t) return true;
          return exists(root->left,t) || exists(root->right,t);
      }
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if(root == p && root == q){
              return root;
          }
          else if(exists(root->right,p) && exists(root->left,q)) return root;
          else if(exists(root->left,p) && exists(root->right,q)) return root;
          else if(root == p && (exists(root->right,q)||exists(root->left,q))) return root;
          else if(root == q && (exists(root->right,p)||exists(root->left,p))) return root;
          else if(exists(root->right,p) && exists(root->right,q))return lowestCommonAncestor(root->right,p,q);
          else return lowestCommonAncestor(root->left,p,q);      
      }
  };