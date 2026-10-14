class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n = d.size();
        string ans = "";
        for(int i = 0;i<n;i++){
            int len = 0;
            string s1 = d[i];
            int j = 0,k = 0;
            while(j < s.length()){
                if(s1[k] == s[j]){k++;} j++;
            }
            if(k == s1.length()){
                if(ans.length() == 0){ans = s1;}
                else if(ans.length() == s1.length() && s1 < ans){ans = s1;}
                else if(ans.length() < s1.length()){ans = s1;}
            }
        }
        return ans;
    }
};