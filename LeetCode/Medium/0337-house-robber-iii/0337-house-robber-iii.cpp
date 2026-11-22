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
    vector<int> solve(TreeNode* root){
        if(!root){return {0,0};}
        vector<int> lh = solve(root->left);
        vector<int> rh = solve(root->right);
        vector<int> options(2);
        options[0] = root->val + lh[1] + rh[1];
        options[1] = max(lh[0],lh[1]) + max(rh[0],rh[1]);
        return options; 
    }
    int rob(TreeNode* root) {
        vector<int> options = solve(root);
        return max(options[0],options[1]);
    }
};