/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root){return "N,";}
        string s  = to_string(root->val) + ",";
        string l = serialize(root->left);
        string r = serialize(root->right);
        return s + l + r;
    }

    TreeNode* solve(string& s,int& i){
        string a;
        while(s[i] != ','){a += s[i]; i++;} i++;
        if(a == "N"){return NULL;}
        int token = stoi(a);
        TreeNode* node = new TreeNode(token);
        node->left = solve(s,i);
        node->right = solve(s,i);
        return node;
    }
    TreeNode* deserialize(string data) {
        int i = 0;
        TreeNode* root = solve(data,i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));