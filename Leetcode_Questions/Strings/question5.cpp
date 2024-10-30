class Solution {
public:
    int gcd(int a,int b){
        if(b==0)
        return a;

        return gcd(b,a%b);
    }
    string gcdOfStrings(string str1, string str2) {
       if(str1+str2 != str2+str1)
       return "";

       int gcdLength=gcd(str1.length(),str2.length());

       return str1.substr(0,gcdLength);
    }
};