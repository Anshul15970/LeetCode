class Solution {
public:
    struct trie{
        trie* children[26];
        bool isend; 
        trie(){
            isend = false;
            for(int i = 0;i<26;i++){
                children[i] = NULL;
            }
        }
    };
    void insert(trie* root, string s){
        trie* node = root;
        for(char c : s){
            int idx = c - 'a';
            if(!node->children[idx]){
                node->children[idx] = new trie();
            }
            node = node->children[idx];
        }
        node->isend = true;
    }

    bool check(trie* root, string s){
        trie* node = root;
        for(char c : s){
            int idx = c - 'a';
            if(!node->children[idx]){
                return false;
            }
            node = node->children[idx];
            if(!node->isend){
                return false;
            }
        }
        return true;
    }

    string longestWord(vector<string>& words) {
        trie* root = new trie();
        for(string s : words){
            insert(root, s);}
        string ans = "";
        for(string s : words){
            bool istrue = check(root,s);
            if(istrue && ans.length() < s.length()){
                ans = s;
            }
            else if(istrue && ans.length() == s.length() && s < ans){
                ans = s;
            }
        }
        return ans;
    }
};