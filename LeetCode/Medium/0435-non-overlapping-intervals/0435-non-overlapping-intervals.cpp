class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];});
        int last = INT_MIN;
        int n = intervals.size();
        int ans = 0;
       for(auto &i : intervals){
        if(last <= i[0]){last = i[1];}
        else{ans++;}
       }
        return ans;
    }
};