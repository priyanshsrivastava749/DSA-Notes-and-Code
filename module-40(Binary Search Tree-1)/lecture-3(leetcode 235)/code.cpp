//the following code is the solution to the leetcode problem number 235
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left,p,q);
       else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
       else return root;
    }
};
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if(root->val == p->val || root -> val == q->val) return root;
//        else if(root->val > p->val && root->val < q->val)return root;
//        else if(root->val > q->val && root->val< p->val)return root;
//        else if(root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left,p,q);
//        else return lowestCommonAncestor(root->right,p,q);
//     }
// };