class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        set<vector<int>> st ; 
        for(int i = 0 ; i < pieces.size() ; i++) {
            st.insert(pieces[i]) ;  
        }
        vector<int> check ; 
        for(int i = 0 ; i < arr.size() ; i++) {
            check.push_back(arr[i]) ; 
            if(st.count(check) >0) {
                while(!check.empty()) {
                    check.pop_back() ; 
                }
            }
        }
        if(check.size() == 0 ) {
            return true ; 
        }
        return false ; 
        
    }
};