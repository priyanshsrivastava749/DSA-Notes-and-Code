/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* first = NULL;
    void parent_mapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        if(root == NULL)return;
        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }
        parent_mapping(root->left,parent);
        parent_mapping(root->right,parent);
    }
    void find(TreeNode* root,int start){
        if(root == NULL)return;
        if(root->val == start){
            first = root;
            return;
        }
        find(root->left,start);
        find(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root,start);
        unordered_map<TreeNode*,TreeNode*> parent;
        parent_mapping(root,parent);
        unordered_set<TreeNode*>isInfected;
        isInfected.insert(first);
        queue<pair<TreeNode*, int>> q;
        q.push({first,0});
        int max_depth = 0;
        while(q.size() > 0){
          TreeNode* node = q.front().first;
          int depth = q.front().second;
          max_depth = max(max_depth,depth);
          q.pop();
          if(node->left){
            if(isInfected.find(node->left)==isInfected.end()){
            isInfected.insert(node->left);
            q.push({node->left,depth + 1});
            }
          }
          if(node->right){
            if(isInfected.find(node->right) == isInfected.end()){
            isInfected.insert(node->right);
            q.push({node->right,depth + 1});
            }
          }
          if(parent.find(node) != parent.end()){
            if(isInfected.find(parent[node])==isInfected.end()){
                isInfected.insert(parent[node]);
                q.push({parent[node],depth + 1});
            }
          }
        }
    return max_depth;
    }
};