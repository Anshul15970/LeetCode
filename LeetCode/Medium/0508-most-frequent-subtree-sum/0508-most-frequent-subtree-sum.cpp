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
    unordered_map<int,int> m;
    int solve(TreeNode* root){
        if(!root){return 0;}
        int a = root->val + solve(root->left) + solve(root->right );
        m[a]++;
        return a;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int a = solve(root);
        vector<int> ans;
        int f = 0;
        for(auto &i: m){
           f = max(f,i.second);}
        for(auto &i:m){
            if(f==i.second){
            ans.push_back(i.first);
            }
        }
        return ans;
    }
};