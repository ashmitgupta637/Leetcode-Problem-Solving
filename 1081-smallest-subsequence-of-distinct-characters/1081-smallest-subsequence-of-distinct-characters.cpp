class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> visited(26, false); 
        stack<char> st ; 
        unordered_map<char , int> freq; 
        for(int i = 0 ; i < s.size() ; i ++) {
            freq[s[i]]++ ;
        }
         
        for(int i = 0; i < s.size() ; i++) {
            freq[s[i]]-- ; 
            if (visited[s[i] - 'a'] == true) continue;
            while(!st.empty() && st.top() > s[i] && freq[st.top()] > 0 ) {
                visited[st.top()- 'a'] = false ;
                st.pop() ; 
            }

            st.push(s[i]) ; 
            visited[s[i] -'a'] = true ; 

            
        }
        string ans = "" ; 
        while(!st.empty()) {
            ans += st.top() ; 
            st.pop() ; 
        }
        reverse(ans.begin() , ans.end()) ; 
        return ans ; 
    }
};