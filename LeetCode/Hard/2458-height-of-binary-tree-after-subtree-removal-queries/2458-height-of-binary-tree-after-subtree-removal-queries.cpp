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
    vector<int> lvl = vector<int>(1000001);
    vector<int> h = vector<int>(100001);
    vector<int> lmax = vector<int>(100001);
    vector<int> lsmax = vector<int>(100001);
    int height(TreeNode* root,int level){
        if(!root){return 0;}
        lvl[root->val] = level;
        h[root->val] = max(height(root->left,level+1),height(root->right,level+1))+1;
        if(lmax[level] < h[root->val]){
            lsmax[level] = lmax[level];
            lmax[level] = h[root->val];
        }
        else if(lsmax[level] < h[root->val]){
            lsmax[level] = h[root->val];
        }
        return h[root->val];
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        int n = q.size();
        vector<int> ans(n,0);
        height(root,0);
        for(int i = 0;i<n;i++){
            int l = lvl[q[i]];
            int a = l + (lmax[l] == h[q[i]] ? lsmax[l] : lmax[l]) - 1;
            ans[i] = max(l-1,a);
        }
        return ans;

    }
};