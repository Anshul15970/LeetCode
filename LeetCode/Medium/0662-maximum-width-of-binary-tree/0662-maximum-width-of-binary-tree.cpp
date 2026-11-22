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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans = 0;
        while(q.size()){
            int s = q.size();
            long long mini = q.front().second;
            long long first,second;
            for(int i = 0;i<s;i++){
                TreeNode* node = q.front().first; 
                long long j = q.front().second - mini;
                q.pop();
                if(i == 0){first = j;}
                if(i == s-1){second = j;}
                if(node->left){q.push({node->left,j*2+1});}
                if(node->right){q.push({node->right,j*2+2});}
            }
            ans = max(ans,second-first+1);
        }
        return ans;
    }
};