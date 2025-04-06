//the following code is the solution to the leetcode problem 1008 https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
class Solution {
public:
    void insert(TreeNode* root,int val){
        if(root == NULL){ root = new TreeNode(val);
        return;}
        else if(root->val > val){
            if(root->left == NULL){
                TreeNode* temp = new TreeNode(val);
                root->left = temp; 
                return;
            }
            insert(root->left,val);
        }
        else{
            if(root->right == NULL){
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
                return;
            }
            insert(root->right,val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }
        return root;
    }
};