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
            if(!node->children[idx]){node->children[idx] = new trie();}
            node = node->children[idx];
        }
        node->isend = true;
    }

    int index(trie* root,string s){
        trie* node = root;
        int i = 0;
        for(i = 0;i<s.length();i++){
            int idx = s[i] - 'a';
            if(!node->children[idx]){return -1;}
            node = node->children[idx];
            if(node->isend){
        return i+1;}
        }
        return -1;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        trie* root = new trie();
        for(string s : dictionary){insert(root,s);}
        vector<string> ans;
        string s1 = "";
        for(char c : sentence){
            if(c == ' '){ans.push_back(s1); s1 = ""; continue;}
            s1 += c;}
            ans.push_back(s1);
        for(int i = 0;i<ans.size();i++){
            int idx = index(root,ans[i]);
            if(idx != -1 && idx < ans[i].length()){
                string s2 = "";
                s2 = ans[i].substr(0,idx);
                if(s2.length() < ans[i].length()){
                    ans[i] = s2;
                }
            }
        }
        string sentence2 = "";
        for(int i = 0;i<ans.size();i++){
            if(i == ans.size()-1){sentence2 += ans[i]; break;}
            sentence2 += ans[i];
            sentence2 += " ";
        }
        return sentence2;
    }
};