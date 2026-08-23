class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int> m;
        for(char c : s){
            m[c]++;
        }
        string ans = "";
        for(auto i : m){
            if(i.first == 'z'){
                int n = m['z']; while(n--){ans += '0';} }
            else if(i.first == 'o'){
                int n = m['o'] - (m['z']+m['w']+m['u']); while(n--){ans+='1';}}
            else if(i.first == 'w'){ int n = m['w']; while(n--){ans+='2';} }
            else if(i.first == 'h'){int n = m['h'] - m['g']; while(n--){ans+='3';}}
            else if(i.first == 'u'){int n = m['u']; while(n--){ans+='4';}}
            else if(i.first == 'f'){int n = m['f']-m['u']; while(n--){ans+='5';}}
            else if(i.first == 'x'){int n = m['x']; while(n--){ans+='6';}}
            else if(i.first == 'v'){int n = m['v'] - (m['f']-m['u']);
            while(n--){ans+='7';}}
            else if(i.first == 'g'){int n = m['g']; while(n--){ans+='8';}}
            else if(i.first == 'i'){int n = m['i']-(m['x']+m['g']+(m['f']-m['u']));
            while(n--){ans+='9';}}
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};