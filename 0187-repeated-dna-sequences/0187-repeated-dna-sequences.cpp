class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> op   ; 
        unordered_map<string , int>  freq ; 
        string news = "" ; 
        for(int i = 0 ; i < 10 ; i++) {
            news.push_back(s[i]) ; 
        }
        freq[news]++ ; 

        for(int i = 10 ; i < s.size() ; i++) {
            int addindex = i ; 
            int removeindex = i-10 ; 
            news.erase(0 , 1) ; 
            news.push_back(s[addindex]) ; 
            freq[news]++ ; 
        }

        for(auto it : freq) {
            if(it.second > 1){
                op.push_back(it.first) ; 
            } 
        }
        return op  ;
        

    }
};