class Solution {
public:
    void reverse(string &s  , int i , int j ){
        while(i <= j){
            char c = s[i] ; 
            s[i] = s[j] ; 
            s[j] = c ; 
            i++  ; 
            j-- ; 
        }
    }
    string reverseParentheses(string s) {
        stack<int> st ; 
        int n = s.size()  ; 
        for(int i = 0 ; i  < n ;i++){
            if(s[i] == '('){
                st.push(i) ; 
            }
        }

        while(!st.empty()){
            int idx = st.top() ; 
            st.pop() ; 
            int end = 0 ; 
            for(int i = idx+1 ; i < n ; i++){
                if(s[i] == ')' ){
                    end = i ; 
                    break ; 
                }
            }
            cout << idx << end << endl ; 
            reverse(s , idx+1 , end-1) ; 
            s.erase(end , 1) ; 
            s.erase(idx ,1) ; 
            cout << s << endl ; 

        }

        return s  ; 
    }
};