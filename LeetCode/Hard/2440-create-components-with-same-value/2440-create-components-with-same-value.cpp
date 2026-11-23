class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> arr;
    int dfs(int parent,int node,int target){
        int val = arr[node];
        for(auto &i : adj[node]){
            if(i == parent){continue;}
            val += dfs(node,i,target);
        }
        if(val == target){return 0;}
        return val;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        arr.resize(n);
        int sum = 0;
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0;i<n;i++){
            sum += nums[i];
            arr[i] = nums[i];
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(sum%i != 0){continue;}
            if(dfs(-1,0,sum/i) != 0){continue;}
            ans = max(ans,i-1);
        }
        return ans;
    }
};