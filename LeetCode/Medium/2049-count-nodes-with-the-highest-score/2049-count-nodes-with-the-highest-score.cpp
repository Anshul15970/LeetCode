class Solution {
public:
    struct TreeNode {
        int val;
        int nodecount;
        TreeNode *left;
        TreeNode *right;
        
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    int countNodes(TreeNode* root){
        if(!root){return 0;}
        root->nodecount = countNodes(root->left) + countNodes(root->right)+1;
        return root->nodecount;
    }
    int countHighestScoreNodes(vector<int>& parent) {
        int n = parent.size();
        long long ans = LLONG_MIN;
        unordered_map<int,int> m;
        vector<TreeNode*> v(n);
        for(int i = 0;i<n;i++){v[i] = new TreeNode();}
        for(int i = 1;i<n;i++){
            if(!v[parent[i]]->left){v[parent[i]]->left = v[i];}
            else{ v[parent[i]]->right = v[i]; }
        }
        countNodes(v[0]);
        for(int i = 0;i<n;i++){
            long long product = 1;
            int l = v[i]->left == NULL ? 0 : v[i]->left->nodecount;
            int r = v[i]->right == NULL ? 0 : v[i]->right->nodecount;
            int parentcnt = n - 1 - l - r;
            if(l>0){product *= l;}
            if(r > 0){product *= r;}
            if(parentcnt > 0){product *= parentcnt;}
            m[product]++;
            ans = max(ans,product);
        }
        return m[ans];
    }
};