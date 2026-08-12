#include <bits/stdc++.h>
using namespace std ; 
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> freq ; 
        int l = 0 ; 
        int n = nums.size() ; 
        int lm = 0 ; 
        for(int r = 0 ; r < n  ; r++){
            freq[nums[r]]++ ; 
            while(freq[nums[r]] > k  && l <= r) {
                freq[nums[l]]-- ; 
                l++  ;
                 
            }
            lm = max(r-l+1 , lm) ; 
        }

        return lm ; 
    }
};