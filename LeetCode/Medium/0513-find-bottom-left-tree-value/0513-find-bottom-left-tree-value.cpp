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
    int findBottomLeftValue(TreeNode* root) {
         if(!root){return NULL;}
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            vector<int> lvl;
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode* node = q.front(); q.pop();
                lvl.push_back(node->val);
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
            ans.push_back(lvl);
        }
        int n = ans.size();
        return ans[n-1][0];
    }
};