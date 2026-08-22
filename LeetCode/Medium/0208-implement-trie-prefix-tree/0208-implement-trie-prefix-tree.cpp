class Trie {
public:
    struct trie{
        trie* children[26];
        bool isend;
    };
    trie* root;
    trie* getnode(){
        trie* root = new trie();
        root->isend = false;
        for(int i = 0;i<26;i++){
            root->children[i] = NULL;
        }
        return root;
    }
    Trie() {
        root = getnode();
    }
    
    void insert(string word) {
        trie* node = root;
    for(char c : word){
            int idx = c - 'a';
            if(!node->children[idx]){
                node->children[idx] = getnode();
            }
            node = node->children[idx];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        trie* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(!node->children[idx]){return false;}
            node = node->children[idx];
        }
        if(node && node->isend){return true;}
        return false;
    }
    
    bool startsWith(string prefix) {
        trie* node = root;
        int i = 0;
        for(i = 0;i<prefix.length();i++){
            int idx = prefix[i] - 'a';
            if(!node->children[idx]){return false;}
            node = node->children[idx];
        }
        if(i == prefix.length()){return true;}
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */