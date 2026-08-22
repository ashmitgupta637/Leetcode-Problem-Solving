#include <bits/stdc++.h>
using namespace std ;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2 ) {
            return 0 ; 
        }

        sort(nums.begin() , nums.end()) ; 
        int sum = 0 ; 
        int diff = abs(nums[1] - nums[0]) ; 
        for(int i = 0 ; i < 2 ; i++){
            sum += nums[i] ; 
        }
         
        int n = nums.size()  ; 
        for(int i = 2 ; i< n ; i++){
            int aidx = i ; 
            int ridx = i-2 ; 
            sum -= nums[ridx] ; 
            sum += nums[aidx] ; 
            int ndiff= nums[aidx] - nums[aidx-1] ; 
            if(ndiff > diff ){
                diff =ndiff; 
            }


        }

        return diff ; 
    }
};