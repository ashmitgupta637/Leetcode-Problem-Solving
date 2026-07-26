class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st ; 
        int drop = nums.size() - k ; 
        int i = 0 ; 
        while(i < nums.size()){ 
            while(!st.empty() && nums[i] < st.top() && drop >0){
                st.pop() ; 
                drop-- ; 
            }
            st.push(nums[i]) ; 
            i++ ; 
        }
        while(drop > 0) {
            st.pop() ; 
            drop-- ; 
        }

        vector<int> res ; 
        while(!st.empty() ) {
            res.push_back(st.top()) ; 
            st.pop() ; 
        }
        reverse(res.begin() , res.end()) ; 
        return res  ;

    }
};