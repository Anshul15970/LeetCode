class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<long long> ans(n, 0);

 
        unordered_map<int, pair<long long, long long>> mp;

      
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            long long count = mp[x].first;
            long long sum = mp[x].second;

         
            ans[i] += (long long)i * count - sum;

    
            mp[x].first++;
            mp[x].second += i;
        }

   
        mp.clear();


        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];

            long long count = mp[x].first;
            long long sum = mp[x].second;

            ans[i] += sum - (long long)i * count;


            mp[x].first++;
            mp[x].second += i;
        }

        return ans;
    }
};