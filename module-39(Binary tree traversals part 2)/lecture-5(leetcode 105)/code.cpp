//THE FOLLOWING CODE GIVEN BELOW IS THE SOLUTION TO THE LEETCODE PROBLEM 105 https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    TreeNode* build(vector<int>& pre,int prelo,int prehi, vector<int>& in,int inlo,int inhi){
        if(inlo>inhi) return NULL;
        TreeNode*root = new TreeNode(pre[prelo]);
        if(prelo == prehi) return root;
        int i = inlo;
        while(i<=inhi){
            if(in[i]==pre[prelo]) break;
            i++;
        }
        int LeftCount = i - inlo;
        int RightCount = inhi - i;
        root->left = build(pre,prelo+1,prelo+LeftCount,in,inlo,i-1);
        root->right = build(pre,prelo+LeftCount+1,prehi,in,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre,0,n-1,in,0,n-1);
    }
};