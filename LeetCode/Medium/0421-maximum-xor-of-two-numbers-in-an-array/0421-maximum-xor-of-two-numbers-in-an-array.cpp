class Solution {
public:
    struct trie{
        trie* left;
        trie* right;
        trie(){
            left = nullptr;
            right = nullptr;
        }
    };
    void insert(trie* root, int &num){
        trie* node = root;
        for(int i = 31;i>=0;i--){
            int i_node = (num>>i)&1;
            if(i_node == 0){
                if(!node->left){
                    node->left = new trie();
                }
                node = node->left;
            }
            else{
                if(!node->right){
                    node->right = new trie();
                }
                node = node->right;
            }
        }
    }

    int getxor(trie* root, int &num){
        trie* node = root;
        int x = 0;
        for(int i = 31;i>=0;i--){
            int ith = (num>>i)&1;
            if(ith == 1){
                if(node->left){
                    x |= (1<<i);
                    node = node->left;
                }
                else{node = node->right;}
            }
            else{
                if(node->right){
                    x |= (1<<i);
                    node = node->right;
                }
                else{node = node->left;}
            }
        }
        return x;
    }

    int findMaximumXOR(vector<int>& nums) {
        trie* root = new trie();
        int m = INT_MIN;
        for(int i : nums){insert(root,i);}
        for(int i = 0;i<nums.size();i++){
            int temp = getxor(root,nums[i]);
            m = max(m,temp);
        }
        return m;
    }
};