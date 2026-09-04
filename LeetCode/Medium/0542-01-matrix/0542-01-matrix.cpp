class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<vector<int>> q;
        vector<vector<int>> ans(n, vector<int> (m,-1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){q.push({i,j}); ans[i][j] = 0;}
            }
        }
        while(q.size()){
            int i = q.front()[0], j = q.front()[1]; q.pop();
            if(i-1>=0 && ans[i-1][j] == -1){q.push({i-1,j}); ans[i-1][j] = ans[i][j]+1;}
            if(j-1>=0 && ans[i][j-1] == -1){q.push({i,j-1}); ans[i][j-1] = ans[i][j]+1;}
            if(i+1<n && ans[i+1][j] == -1){q.push({i+1,j}); ans[i+1][j]  = ans[i][j]+1;}
            if(j+1<m && ans[i][j+1] == -1){q.push({i,j+1}); ans[i][j+1] = ans[i][j]+1;}
        }
        return ans;
    }
};