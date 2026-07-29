class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt = 0 ; 
        stack<int> st ; 
        int i = 0 ; 
        int n = arr.size() ; 
        while(i < n ){
            if(st.empty() || arr[i] > st.top()){
                st.push(arr[i]) ; 
            }
            if(st.top() == i) {
                cnt++ ; 
            }
            i++ ; 
        }

        return cnt ; 

    }
};