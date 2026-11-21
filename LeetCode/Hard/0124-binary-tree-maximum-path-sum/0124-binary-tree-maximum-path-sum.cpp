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
    int maxsum;
    int solve(TreeNode* root){
        if(!root){return 0;}
        int l = solve(root->left);
        int r = solve(root->right);
        int first = l + r + root->val;
        int second = max(l,r) + root->val;
        int third = root->val;
        maxsum = max({maxsum,first,second,third});
        return max(second,third);
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};