class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string s1 = "",s2 = "",t1 = "",t2 = "";
        int n1 = num1.length(),n2 = num2.length();
        int i1 = n1-1,i2 = n2-1;
        while(num1[i1] == 'i'){i1--;}
        while(num2[i2] == 'i'){i2--;}
        while(num1[i1] >= '0' && num1[i1] <= '9'){s1 += num1[i1--];}
        s1 += num1[i1];
        reverse(s1.begin(),s1.end());
        while(num2[i2] >= '0' && num2[i2] <= '9'){s2 += num2[i2--];}
        s2 += num2[i2];
        reverse(s2.begin(),s2.end());
        i1 = 0,i2 = 0;
        t1 += num1[i1++]; t2 += num2[i2++];
        while(num1[i1] >= '0' && num1[i1] <= '9'){t1 += num1[i1++];}
        while(num2[i2] >= '0' && num2[i2] <= '9'){t2 += num2[i2++];}
        int a1 = stoi(t1),b1 = stoi(s1),a2 = stoi(t2),b2 = stoi(s2);
        int c1 = (a1 * a2) + (b1 * b2 * -1); 
        int c2 = (a1 * b2) + (b1 * a2);
        return to_string(c1)+"+"+to_string(c2)+"i";
    }
};