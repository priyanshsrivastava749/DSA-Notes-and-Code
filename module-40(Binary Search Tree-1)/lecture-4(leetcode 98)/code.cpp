//the following code contains the solution to the leetcode problem number 98 https://leetcode.com/problems/validate-binary-search-tree/
//BRUTE FORCE SOLUTION
// class Solution {
// public:
//     long long max_in_node(TreeNode* root){
//         if(root == NULL) return LLONG_MIN;
//         return max((long long)root->val , max(max_in_node(root->left),max_in_node(root->right)));
//     }
//     long long min_in_node(TreeNode* root){
//         if(root == NULL) return LLONG_MAX;
//         return min((long long)root->val , min(min_in_node(root->left),min_in_node(root->right)));
//     }
//     bool isValidBST(TreeNode* root){
//         if(root == NULL) return true;
//         else if((long long)root->val <= max_in_node(root->left)) return false;
//         else if((long long)root->val >= min_in_node(root->right)) return false;
//         else return isValidBST(root->left) && isValidBST(root->right);
//     }
// };
//OPTIMISED SOLUTION
class Solution{
    public:
    void in_order(TreeNode* root,vector<int> &v){
        if(root == NULL)return;
        in_order(root->left,v);
        v.push_back(root->val);
        in_order(root->right,v);
    }
    bool isValidBST(TreeNode* root){
        vector<int> v;
        in_order(root,v);
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>=v[i+1])return false;
        }
        return true;
    }
};
