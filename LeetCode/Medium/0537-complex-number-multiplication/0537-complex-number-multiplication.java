class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        String s1 = "",s2 = "",t1 = "",t2 = "";
        int n1 = num1.length(),n2 = num2.length();
        int i1 = n1-1,i2 = n2-1;
        while(num1.charAt(i1) == 'i'){i1--;}
        while(num2.charAt(i2) == 'i'){i2--;}
        while(num1.charAt(i1) >= '0' && num1.charAt(i1) <= '9'){s1 += num1.charAt(i1); i1--;}
        s1 += num1.charAt(i1);
        s1 = new StringBuilder(s1).reverse().toString();
        while(num2.charAt(i2) >= '0' && num2.charAt(i2) <= '9'){s2 += num2.charAt(i2); i2--;}
        s2 += num2.charAt(i2);
        s2 = new StringBuilder(s2).reverse().toString();
        i1 = 0; i2 = 0;
        t1 += num1.charAt(i1); i1++; t2 += num2.charAt(i2); i2++;
        while(num1.charAt(i1) >= '0' && num1.charAt(i1) <= '9'){t1 += num1.charAt(i1); i1++;}
        while(num2.charAt(i2) >= '0' && num2.charAt(i2) <= '9'){t2 += num2.charAt(i2); i2++;}
        int a1 = Integer.parseInt(t1),b1 = Integer.parseInt(s1),a2 = Integer.parseInt(t2),b2 = Integer.parseInt(s2);
        int c1 = (a1 * a2) + (b1 * b2 * -1); 
        int c2 = (a1 * b2) + (b1 * a2);
        return c1+"+"+c2+"i";
    }
}