class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        unordered_map<string,int> map,vis;
        q.push({startGene,0});
        for(string &i : bank){map[i] = 1;}
        while(q.size()){
            string w = q.front().first; int val = q.front().second;
            q.pop();
            for(int i = 0;i<endGene.size();i++){
                string w1 = w,w2 = w,w3 = w,w4 = w;
                w1[i] = 'A'; w2[i] = 'C'; w3[i] = 'G'; w4[i] = 'T';
                if(map.count(w1) && !vis[w1]){
                    if(w1 == endGene){return val+1;} q.push({w1,val+1}); vis[w1] = 1;}
                if(map.count(w2) && !vis[w2]){
                    if(w2 == endGene){return val+1;} q.push({w2,val+1}); vis[w2] = 1;}
                if(map.count(w3) && !vis[w3]){
                    if(w3 == endGene){return val+1;} q.push({w3,val+1}); vis[w3] = 1;}
                if(map.count(w4) && !vis[w4]){
                    if(w4 == endGene){return val+1;} q.push({w4,val+1}); vis[w4] = 1;}
        }}
        return -1;
    }
};