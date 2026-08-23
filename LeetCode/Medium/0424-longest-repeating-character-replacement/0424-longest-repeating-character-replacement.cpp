class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int n = s.length();
        int size = 0,mlen = INT_MIN;
        for(int i = 0;i<n;i++){
            m[s[i]]++;
            size++;
            int mfreq = INT_MIN;
            for(auto &j : m){mfreq = max(mfreq,j.second);}
            if(size - mfreq <= k){mlen = max(mlen,size);}
            else{size--; m[s[i-size]]--;}
        }
        return mlen;
    }
};