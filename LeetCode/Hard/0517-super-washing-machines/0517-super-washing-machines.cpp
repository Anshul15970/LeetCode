class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = 0;
        int balance = 0;
        int ans = 0;
        for(int i : machines){total += i;}
        if(total%n != 0){return -1;}
        int target = total/n;
        for(int i : machines){
            int diff = i-target;
            balance += diff;
            ans = max({ans,abs(balance),diff});
        }
        return ans;
    }
};