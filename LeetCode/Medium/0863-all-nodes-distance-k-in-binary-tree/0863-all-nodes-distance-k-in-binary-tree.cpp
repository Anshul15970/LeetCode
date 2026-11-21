/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(unordered_map<TreeNode*, TreeNode*>& parent,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            if(node->left){q.push(node->left); parent[node->left] = node;}
            if(node->right){q.push(node->right); parent[node->right] = node;}
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        solve(parent,root);
        unordered_map<TreeNode*, int> vis;
        vis[target] = 1; 
        queue<TreeNode*> q;
        q.push(target);
        int dist = 0;
        vector<int> ans;
        while(q.size()){
            if(dist == k){break;}
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left && !vis.count(node->left)){
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if(node->right && !vis.count(node->right)){
                    q.push(node->right);
                    vis[node->right] = 1;
                }
                if(parent.count(node) && !vis.count(parent[node])){
                    q.push(parent[node]);
                    vis[parent[node]] = 1;
                }
            }
            dist++;
        }
        while(q.size()){ans.push_back(q.front()->val); q.pop();}
        return ans;
    }
};