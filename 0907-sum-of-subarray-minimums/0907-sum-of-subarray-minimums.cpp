#include <iostream> 
#include <vector>
#include <stack> 
using namespace std ; 

class Solution{
    public: 

    vector<int> findNSE(vector<int>& arr) {
        stack<int> st  ; 
        int n = arr.size() ;
        vector<int> nse(n) ; 
         

        for(int i = n-1 ; i>=0  ; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop() ; 

            }
            nse[i] = st.empty() ? n : st.top() ; 
            st.push(i) ; 
        }
        return nse ; 
    }
    vector<int> findPSEE(vector<int> & arr) {
        stack<int> st ;  
        int n = arr.size() ; 
        vector<int> psee(n) ; 
        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && arr[st.top()] >arr[i]) {
                st.pop() ; 
            }
            psee[i] = st.empty()  ? -1 : st.top() ; 
            st.push(i) ; 
        }
        return psee ; 
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size() ; 
        vector<int> nse = findNSE(arr)   ; 
        vector<int> pse = findPSEE(arr) ; 
        int total = 0 ; 
        int mod = (int)(1e9+7) ; 
        for(int i = 0 ; i < n; i++) {
            long long left = i - pse[i] ; 
            long long right = nse[i] -i ; 

            total = (total + (1LL*left*right*arr[i])%mod)%mod ; 

        }
        return total ; 
    }
};
