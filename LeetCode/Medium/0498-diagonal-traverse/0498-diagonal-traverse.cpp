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

                // Move up-right
                while (i >= 0 && j < m) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }

                // Find next starting point
                if (j == m) {
                    i += 2;
                    j--;
                }
                else {
                    i++;
                }

                flag = false;
            }

            else {

                // Move down-left
                while (i < n && j >= 0) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }

                // Find next starting point
                if (i == n) {
                    j += 2;
                    i--;
                }
                else {
                    j++;
                }

                flag = true;
            }
        }

        return ans;
    }
};