// the following code contain the solution of leetcode problem: https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    int level(TreeNode* root){
        if(root == NULL)return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    void pre_order(TreeNode* root,int lvl,vector<int>& ans){
        if(root == NULL)return;
        ans[lvl] = root->val;
        pre_order(root->left,lvl+1,ans);
        pre_order(root->right,lvl+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(level(root),0);
        pre_order(root,0,ans);
        return ans;
    }
};
