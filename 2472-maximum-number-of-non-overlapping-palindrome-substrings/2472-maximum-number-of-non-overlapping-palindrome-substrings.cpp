
class Solution {
public:
    int n ; 
    bool ispalind(string s , int i , int j){
        while(i <= j ){
            if(s[i] != s[j]){
                return false ;
            }
            i++; 
            j-- ; 
        }

        return true ; 

    }
    // int solve(string s , int k , int i, int j , vector<vector<int>> &dp) {
     
    //     if( i >= n ||  j >= n) || i>j{
    //         return 0 ; 

    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j] ; 
    //     }
    //     if((j-i+1)ispalind(s , i , j)) {
    //         int take = 1 + solve(s , k , j + 1 , j + k , dp) ; 
    //         int grow  = solve(s , k , i , j+1, dp) ; 
    //         int slide = solve(s , k , i+1 , j+1 , dp) ; 

    //         return dp[i][j] = max({take , slide , grow }) ; 

    //     }
    //     int grow  = solve(s , k , i , j+1 , dp) ; 
    //     int slide = solve(s , k , i+1 , j+1 , dp ) ; 

    //     return dp[i][j] = max(grow  , slide) ; 

//     int maxPalindromes(string s, int k) {
//         n = s.length();
//         if(k == 1) {
//             return n ; 
//         }

//         vector<vector<int>> dp(n+1, vector<int>(n+1));

//         for(int i = n -1 ; i >= 0 ; i--){
//             for(int  j = n-1 ; j >= 0 ; j--){
//                 if(ispalind(s , i , j)){
//                     int take = 1 +(j+ k <= n ? dp[j+1][j+k] : 0) ; 
//                     int grow = dp[i][j+1] ;  
//                     int slide = dp[i+1][j+1] ; 

//                     dp[i][j] = max({take , grow  , slide}) ; 


//                 }
//                 int grow = dp[i][j+1] ; 
//                 int slide = dp[i+1][j+1] ; 
//                 dp[i][j] = max({dp[i][j] , grow , slide}) ; 
//             }
//         }
//         return dp[0][k-1] ; 
//     }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        if (k == 1) return n;

        int count = 0;
        int i = 0;

        while (i < n) {
            bool found = false;
           
            for (int len = k; len <= k + 1 && i + len <= n; ++len) {
                if (ispalind(s, i, i + len - 1)) {
                    count++;
                    i = i + len; 
                    found = true;
                    break;
                }
            }
            if (!found) {
                i++;
            }
        }
        return count;
    }

};