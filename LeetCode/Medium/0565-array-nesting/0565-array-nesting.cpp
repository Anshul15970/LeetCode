class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int cnt1=  0;
        vector<int> vis(n,false);
        for(int i : nums){
            int cnt = 1;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while(q.size()){
                int node = q.front(); q.pop();
                int next = nums[node];
                if(!vis[next]){q.push(next); vis[next] = true; cnt++;}
            }
        cnt1 = max(cnt1,cnt);
        }
        return cnt1;
    }
};