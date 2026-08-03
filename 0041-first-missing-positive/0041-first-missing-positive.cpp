class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int expected = 1  ; 
        int n = nums.size() ; 
        sort(nums.begin() , nums.end()) ;
        int i = 0 ; 
        while(i < n ){
            if(nums[i] <=0 ) i++ ; 
            else{
                break ; 
            }
        }
        while(i < n){
            if (i > 0 && nums[i] == nums[i-1]) {
                i++;
                continue;
            }
            if(nums[i] == expected) expected++  , i++; 
            else if(nums[i] > expected) return expected ; 
        }
        return expected ; 
    }
};