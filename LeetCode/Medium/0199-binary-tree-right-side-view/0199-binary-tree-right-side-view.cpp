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
    int height(TreeNode* root){
           if(!root){return 0;}
           int a = height(root->left);
           int b = height(root->right);
           return max(a,b) + 1;
       }
       void solve(TreeNode* root,vector<vector<int>>& ans, int level){
           if(!root){return;}
           ans[level].push_back(root->val);
           solve(root->right, ans,level+1);
           solve(root->left, ans, level+1);
       }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans(height(root));
       solve(root, ans, 0);
       vector<int> v;
       for(int i = 0;i<ans.size();i++){
           cout << "[";
           for(auto &j : ans[i]){cout << j << ",";}
           cout << "],";
           v.push_back(ans[i][0]);
       }
       
       return v;
    }
};