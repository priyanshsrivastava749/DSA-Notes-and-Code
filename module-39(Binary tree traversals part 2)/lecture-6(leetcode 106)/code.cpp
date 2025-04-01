//the following code is the solution to the leetcode problem number 106
class Solution {
public:
    TreeNode* build(vector<int>&in,int inlo,int inhi,vector<int>& post,int postlo,int posthi){
        if(inlo>inhi) return NULL;
        TreeNode* root = new TreeNode(post[postlo]);
        if(postlo == posthi) return root;
        int i = inlo;
        while(i<=inhi){
            if(in[i] == post[postlo]) break;
            i++;
        }
        int rightCount = inhi - i;
        int leftCount = i - 1;
        root->right = build(in,i+1,inhi,post,postlo+1,postlo+rightCount);
        root->left = build(in,inlo,i-1,post,postlo+rightCount+1,posthi);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        reverse(postorder.begin(),postorder.end());
        return build(inorder,0,n-1,postorder,0,n-1);
    }
};