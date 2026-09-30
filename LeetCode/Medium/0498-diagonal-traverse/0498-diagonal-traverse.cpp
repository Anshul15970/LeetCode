class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        int i = 0, j = 0;
        bool flag = true;
        while (i < n && j < m) {
            int p = i, q = j;
            if (flag) {
                while (i >= 0 && j < m) {ans.push_back(mat[i][j]); i--; j++;}
                if (j == m) {i += 2; j--;}
                else {i++;}
                flag = false;
            }
            else {
                while (i < n && j >= 0) {ans.push_back(mat[i][j]); i++; j--; }
                if (i == n) {j += 2; i--; }
                else {j++; }
                flag = true;
            }
        }
        return ans;
    }
};