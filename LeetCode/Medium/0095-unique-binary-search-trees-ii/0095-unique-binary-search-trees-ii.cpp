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
    map<pair<int,int>,vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int s,int e){
        if(s > e){return {NULL};}
        if(dp.count({s,e})){return dp[{s,e}];}
        if(s == e){TreeNode* root = new TreeNode(s); return dp[{s,e}] = {root};}
        vector<TreeNode*> result;
        for(int  k= s;k<=e;k++){
            vector<TreeNode*> l = solve(s,k-1);
            vector<TreeNode*> r = solve(k+1,e);
            for(auto& i : l){
                for(auto &j : r){
                TreeNode* node = new TreeNode(k);
                node->left = i;
                node->right = j;
                result.push_back(node);
            }}
        }
        return dp[{s,e}] = result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};