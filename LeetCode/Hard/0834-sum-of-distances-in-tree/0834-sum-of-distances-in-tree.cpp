class Solution {
public:
    vector<int> count;
    int N;
    int root_result = 0;
    int dfs(unordered_map<int,vector<int>>& m,int prev,int curr,int curr_depth){
        int total_count = 1;
        root_result += curr_depth;
        for(auto &i : m[curr]){
            if(i == prev){continue;}
            total_count += dfs(m,curr,i,curr_depth+1);
        }
        count[curr] = total_count;
        return total_count;
    }
    void DFS(unordered_map<int,vector<int>>& m,int prev,int curr,vector<int>& result){
        for(auto &i : m[curr]){
            if(prev == i){continue;}
            result[i] = result[curr] - count[i] + (N-count[i]);
            DFS(m,curr,i,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count.resize(n,0);
        unordered_map<int,vector<int>> m;
        for(auto &i : edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        vector<int> result(n,0);
        dfs(m,-1,0,0);
        result[0] = root_result;
        DFS(m,-1,0,result);
        return result;
    }
};