class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "" ; 
        for(char ch : num) {
            while(!res.empty()  && res.back() > ch && k>0) {
                res.pop_back() ; 
                k-- ; 
            }
            res.push_back(ch) ; 
        }
        while(k > 0 && !res.empty()) {
            res.pop_back() ; 
            k-- ; 
        }
        int start = 0 ; 
        while(start < res.size() && res[start] == '0' ) {
            start++; 
        }
        res = res.substr(start) ; 

        return res.empty() ? "0" : res ; 
    }
};