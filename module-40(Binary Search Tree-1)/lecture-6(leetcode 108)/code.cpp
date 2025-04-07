class Solution {
public:
    TreeNode* construct(vector<int>& nums,int lo,int hi){
        int mid = lo + (hi-lo)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(lo > hi) return NULL;
        else if(lo == hi) return root;
        root->left = construct(nums,lo,mid-1);
        root->right = construct(nums,mid+1,hi);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {  
        return construct(nums,0,nums.size()-1);
    }
};