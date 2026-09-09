class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int cnt = 0;
        queue<pair<string,int>> q;
        unordered_map<string,int> map,vis;
        q.push({beginWord,1});
        for(auto &i : wordList){map[i] = 1;}
        while(q.size()){
            string w = q.front().first; int val = q.front().second;
            q.pop();
            for(int j = 0;j<w.size();j++){
                string w1 = w;
                for(int k = 0;k<26;k++){
                    w1[j] = k+'a';
                    if(!vis[w1] && map.count(w1)){
                        if(w1 == endWord){return val+1;}
                        q.push({w1,val+1}); vis[w1] = 1;}
                }
            }
        }
        return 0;
    }
};