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
    void solve(TreeNode* root,int l,int val,int d){
        if(!root){return;}
        if(l == d){
            TreeNode *n1 = new TreeNode(val);
            TreeNode *n2 = new TreeNode(val);
            TreeNode *oldleft = root->left;
            TreeNode *oldright = root->right;
            n1->left = oldleft;
            n2->right = oldright;
            root->left = n1;
            root->right = n2;
            return;
        }
        solve(root->left,l+1,val,d);
        solve(root->right,l+1,val,d);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root){return NULL;}
        if(depth == 1){
            TreeNode* n1 = new TreeNode(val);
            n1->left = root;
            return n1;
        }
        solve(root,1,val,depth-1);
        return root;
    }
};