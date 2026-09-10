class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],0,0});
        while(pq.size()){
            auto [cost,i,j] = pq.top(); pq.pop();
            if(cost > dist[i][j]){continue;}
            if(i == n-1 && j == n-1){return cost;}
            if(i-1 >= 0){int newcost = max(cost,grid[i-1][j]); 
            if(newcost < dist[i-1][j]){dist[i-1][j] = newcost;
            pq.push({newcost,i-1,j});}}
            if(j-1 >= 0){int newcost = max(cost,grid[i][j-1]);
            if(newcost < dist[i][j-1]){dist[i][j-1] = newcost;
            pq.push({newcost,i,j-1});}}
            if(i+1 < n){int newcost = max(cost,grid[i+1][j]);
            if(newcost < dist[i+1][j]){dist[i+1][j] = newcost;
            pq.push({newcost,i+1,j});}}
            if(j+1 < n){int newcost = max(cost,grid[i][j+1]);
            if(newcost < dist[i][j+1]){dist[i][j+1] = newcost;
            pq.push({newcost,i,j+1});}}
        }
        return -1;
    }
};