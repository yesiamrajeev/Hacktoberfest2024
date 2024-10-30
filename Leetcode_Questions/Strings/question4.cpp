class Solution {
public:
    string reverseVowels(string s) {
        vector<char>ch;
        string ans;

        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                ch.push_back(s[i]);
                s[i]='/';
            }
        }

        reverse(ch.begin(),ch.end());
        int i=0;
        int j=0;
        while(i<s.length() && j<ch.size()){
            if(s[i]=='/'){
                s[i]=ch[j];
                j++;
            }
            i++;
            
        }
        return s;
    }
};