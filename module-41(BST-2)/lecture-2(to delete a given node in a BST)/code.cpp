// the following code is the solution to leetcode problem 450 https://leetcode.com/problems/delete-node-in-a-bst/
class Solution {
public:
    TreeNode* in_predecessor(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            if(root->left == NULL && root->right == NULL)return NULL;
            if(root->left == NULL || root->right == NULL){
                if(root->left != NULL)return root->left;
                else return root->right;
            }
            if(root->left != NULL && root->right != NULL){
                TreeNode* pred = in_predecessor(root);
                root->val = pred->val;
                root->left = deleteNode(root->left,pred->val);
            }
        }
        else if(root->val > key){
            //move left
            root->left = deleteNode(root->left,key);
        }
        else{
            //move right
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};