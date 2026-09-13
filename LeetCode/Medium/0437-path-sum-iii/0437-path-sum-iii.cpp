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
    int solve(TreeNode* root,long long sum, int t){
        if(!root){return 0;}
        int ans = 0;
        sum += root->val;
        if(sum == t){ans++;}
        ans += solve(root->left,sum,t);
        ans += solve(root->right,sum,t);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){return 0;}
        return solve(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};