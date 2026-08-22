class Solution {
public:
    struct trienode{
        trienode* children[26];
        bool isend;
        trienode(){
            isend = false;

            for(int i = 0;i<26;i++){
                children[i] = nullptr;
            }
        }
    };

    void insert(trienode* root, string s){
        trienode* node = root;
        for(char c : s){
            int i = c - 'a';
            if(!node->children[i]){
                node->children[i] = new trienode();
            }
            node = node->children[i];
        }
        node->isend = true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        trienode* root = new trienode();
        for(int i = 0;i<wordDict.size();i++){
            insert(root,wordDict[i]);}
            int n = s.length();
        vector<bool> dp(n,false);
        dp[0] = true;
        for(int i = 0;i<n;i++){
            trienode* node = root;
            if(!dp[i]){continue;}
            for(int j = i;j<n;j++){
                int idx = s[j]-'a';
                if(!node->children[idx]){
                    break;}
                node = node->children[idx];
                if(node->isend){dp[j+1] = true;}
            }
        }
        return dp[n];
    }
};