//the following code contain the solution to the leetcode problem number 1038 https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
class Solution {
public:
    int sum = 0;
    void rev_in_order(TreeNode* root){
        if(root == NULL)return;
        rev_in_order(root->right);
        root->val += sum;
        sum = root->val;
        rev_in_order(root->left);
    }
    TreeNode* bstToGst(TreeNode* root){
      rev_in_order(root);
      return root;
    }
};