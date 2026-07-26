class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st ; 
        vector<int> count(26 , 0) ; 
        int i = 0 ; 
        vector<bool> visited(26 , false) ;  
        for(int i =  0 ; i <  s.size() ; i++){
            count[s[i] - 'a']++ ; 
        }
        for(int i = 0 ; i < s.size() ; i++) {  
            char curr = s[i] ; 
            count[curr - 'a']-- ; 
            if(visited[curr-'a']) continue ; 
            while(!st.empty() && count[st.top() -'a'] >0 && st.top()> curr){
                
                visited[st.top()- 'a'] = false ; 
                st.pop() ; 

            }
            st.push(curr) ; 
            visited[curr- 'a'] = true  ; 
            
        }

        string news = "" ; 
        while(!st.empty()){
            news.push_back(st.top()) ; 
            st.pop() ; 
        }
        reverse(news.begin() , news.end()) ; 
        return news ; 

    }
};