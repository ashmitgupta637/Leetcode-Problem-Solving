class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
        vector<pair<char,  int>> blocks ;
        int i = 0 ; 
        while(i< s.size()){
            int cnt = 0 ; 
            if( s[i] == '1'){
                while(i < s.size() && s[i] == '1' ){
                    cnt++ ; 
                    i++ ;
                }
            }
            else{
                while(i < s.size() && s[i] == '0') {
                    cnt++ ;
                    i++ ; 

                }
            }
            blocks.push_back({s[i-1] , cnt}) ; 
            
        }
         int totalOnes = 0;
        for (auto &x : blocks) {
            if (x.first == '1')
                totalOnes += x.second;
        }

        int ans = totalOnes;

        for (int i = 1; i < blocks.size() - 1; i++) {
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                int merged = blocks[i - 1].second +
                             blocks[i].second +
                             blocks[i + 1].second;

                int candidate = totalOnes - blocks[i].second + merged;

                ans = max(ans, candidate);
            }
        }

        return ans;
    }
};