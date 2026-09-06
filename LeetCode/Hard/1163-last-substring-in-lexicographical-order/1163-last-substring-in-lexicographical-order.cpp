class Solution {
public:
    string lastSubstring(string s) {
        int n = s.length();
        int i = 0,j = 1, k = 0;
        while(i<n && j<n && i+k<n && j+k<n){
            if(s[i+k] == s[j+k]){k++;}
            else if(s[i+k] < s[j+k]){ i = i+k+1; k = 0;}
            else{j = j+k+1; k = 0;}
            if(i==j){j++;}
        }
        return s.substr(i);
    }
};