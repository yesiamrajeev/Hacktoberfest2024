#include <string>
#include <vector>

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n=sentence1.length();
        int m=sentence2.length();
        if(n<m){
            swap(sentence1,sentence2);
        }
        vector<string>vec1,vec2;

        stringstream ss1(sentence1);
        string token;

        while(ss1 >> token){
            vec1.push_back(token);
        }

        stringstream ss2(sentence2);
         while(ss2 >> token){
            vec2.push_back(token);
        }

    

        int i=0,j=vec1.size()-1;
        int k=0,l=vec2.size()-1;
        
        while(k<vec2.size() && i<vec1.size() && vec2[k]==vec1[i]){
            k++;
            i++;
        }

        while(l>=k && vec2[l]==vec1[j]){
            j--;
            l--;
        }

        return l<k;
    }
};