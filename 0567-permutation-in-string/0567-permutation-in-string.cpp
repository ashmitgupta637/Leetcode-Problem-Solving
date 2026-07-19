class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> x(26) ;  // s2 
        vector<int> y(26) ;  // s1
        if(s2.size() < s1.size()) {
            return false ;
        }
        for(int i = 0 ; i < s1.size() ; i++) {
            x[s2[i] - 'a']++ ; 
            y[s1[i] - 'a']++ ; 

        }
        if(x == y) {
            return true ; 
        }
        for(int i = s1.size() ; i< s2.size() ; i++) {
            int removeindex = i-s1.size() ; 
            int addindex  = i ; 
            x[s2[addindex]-'a']++ ; 
            x[s2[removeindex]-'a']-- ; 
            if(x== y) return true ; 
        }
        return false ; 
    }
};