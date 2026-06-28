class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 ;
        int right = 0 ; 
        int maxlen = 0 ; 
        int zeroes = 0 ; 
        while(right < nums.size()) {
            if(nums[right] == 0 ) zeroes++  ;
            while(zeroes > k ) {
                if(nums[left] == 0 ) zeroes-- ; 
                left++ ; 
            }
            if(zeroes <= k ){
                maxlen=  max(maxlen , right-left+1 ) ; 
                
            }
            right++ ; 
        }
        return maxlen; 
    }
};