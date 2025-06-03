 class Solution {
  public:
      void trim(TreeNode* root,int lo,int hi){
          if(root == NULL) return;
          while(root->left != NULL){
              if(root->left->val < lo){
                  root->left = root->left->right;
              }
              else if(root->left->val > hi){
                  root->left = root->left->left;
              }
              else break;
          }
          while(root->right != NULL){
              if(root->right->val > hi){
                  root->right = root->right->left;
              }
              else if(root->right->val < lo){
                  root->right = root->right->right;
              }
              else break;
          }
          trim(root->left,lo,hi);
          trim(root->right,lo,hi);
      }
      TreeNode* trimBST(TreeNode* root, int low, int high) {
          TreeNode* temp = new TreeNode(INT_MAX);
          temp -> left = root;
          trim(temp,low,high);
          return temp->left;
      }
  };