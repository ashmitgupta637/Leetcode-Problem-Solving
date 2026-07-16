class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> arr ; 

        for(int i  = 0 ; i < nums.size() ; i++) {
            int n= nums[i] ;
            string s  = to_string(n) ;  
            for(char c : s) {
                int digit  = c-'0' ; 
                arr.push_back(digit) ; 
            }
        }
        return arr ; 
    }
};