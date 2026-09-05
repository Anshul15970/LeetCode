class Solution {
public:
    vector<int> lps(string s){
        int i = 1, len = 0;
        vector<int> LPS(s.length(),0);
        while(i<s.length()){
            if(s[i] == s[len]){len++; LPS[i] = len; i++;}
            else if(len != 0){len = LPS[len-1];}
            else{LPS[i] = 0; i++;}
        }
        return LPS;
    }
    string longestPrefix(string s) {
        vector<int> LPS = lps(s);
        int n = s.length();
        return s.substr(0,LPS[n-1]);
    }
};