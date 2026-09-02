class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> map;
    unordered_map<string,bool> visited;
    double solve(string a,string b,double p){
        if(a == b){return p;}
        visited[a] = true;
        for(auto [neighbour,val] : map[a]){
            if(!visited[neighbour]){
                double result = solve(neighbour,b,p*val);
                if(result != -1.0){return result;}
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i = 0;i<n;i++){
            string u = equations[i][0];
            string v = equations[i][1];
            map[u].push_back({v,values[i]});
            map[v].push_back({u,1/values[i]});
        }
        vector<double> ans;
        int m = queries.size();
        for(int i = 0;i<m;i++){
            visited.clear();
            if(!map.count(queries[i][0]) || !map.count(queries[i][1])){
                ans.push_back(-1);
                continue;
            }
            double r = solve(queries[i][0],queries[i][1],1);
            ans.push_back(r);
        }
        return ans;
    }
};