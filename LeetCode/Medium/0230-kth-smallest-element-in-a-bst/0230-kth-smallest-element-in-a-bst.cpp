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
    int inorder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){return -1;}
        if(root->left){
            int leftk = kthSmallest(root->left, k);
            if(leftk != -1){return leftk;}
        }
        if(inorder+1 == k){return root->val;}
        inorder += 1;
        if(root->right){
            int rightk = kthSmallest(root->right, k);
            if(rightk != -1){return rightk;}
        }
        return -1;
    }
};