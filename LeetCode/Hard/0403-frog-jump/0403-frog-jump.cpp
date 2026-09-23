class Solution {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> dp;

    bool solve(vector<int>& stones, int i, int k) {

        if (i == stones.size() - 1)
            return true;

        if (dp[i][k] != -1)
            return dp[i][k];

        for (int jump = k - 1; jump <= k + 1; jump++) {

            if (jump <= 0)
                continue;

            int next = stones[i] + jump;

            if (mp.count(next)) {
                int nextIndex = mp[next];

                if (solve(stones, nextIndex, jump))
                    return dp[i][k] = true;
            }
        }

        return dp[i][k] = false;
    }

    bool canCross(vector<int>& stones) {

        if (stones[1] != 1)
            return false;

        for (int i = 0; i < stones.size(); i++)
            mp[stones[i]] = i;

        int n = stones.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(stones, 1, 1);
    }
};