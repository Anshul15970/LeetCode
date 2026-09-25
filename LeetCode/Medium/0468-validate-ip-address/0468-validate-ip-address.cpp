class Solution {
public:
    string validIPAddress(string q) {
        int n = q.length();
        int cnt1 = 0,cnt2 = 0;
        for(char c : q){if(c=='.'){cnt1++;} if(c == ':'){cnt2++;}}
        if(cnt1 == 3){
            unordered_map<char,int> m;
            string s = "";
            for(char c : q){
                if(c == '.'){
                    if(s.length() == 0 || s.length() > 3){return "Neither";}
                    int num = stoi(s);
                    if((s.length() > 1 && s[0] == '0')){return "Neither";}
                    else if(num < 0 || num > 255){
                        return "Neither";
                    }
                     s.clear();}
                else if(c <= '9' && c >= '0'){s += c;}
                else{return "Neither";}
            }
            if(s.length() == 0 || s.length() > 3){return "Neither";}
                    int num = stoi(s);
                    if(s.length() > 1 && (s[0] == '0' || s.length() > 3)){return "Neither";}
                    else if(num < 0 || num > 255){
                        return "Neither";
                    }
            return "IPv4";
        }
        if(cnt2 == 7){
            string s = "";
            unordered_map<char,int> m;
            for(int i = 'A';i<='F';i++){m[char(i)]++;}
            for(int i = 'a';i<='f';i++){m[char(i)]++;}
            for(int i = '0';i<='9';i++){m[char(i)]++;}
            for(char c : q){
                if(c == ':'){
                    if(s.length() > 4 || s.length() == 0){return "Neither";}
                    s.clear();
                }
                else if(m.count(c)){s += 'c';}
                else{return "Neither";}
            }
            if(s.length() > 4 || s.length() == 0){return "Neither";}
            return "IPv6";
        }
        return "Neither";
    }
};