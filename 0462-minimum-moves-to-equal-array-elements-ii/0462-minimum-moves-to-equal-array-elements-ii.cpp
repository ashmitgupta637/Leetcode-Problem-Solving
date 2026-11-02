class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ; 
        int n = nums.size() ; 
        int cnt = 0 ; 
        int med_idx = n/2  ; 
        for(int i =0 ; i < nums.size() ; i++){
            int med = nums[med_idx] ; 
            
            cnt += abs(nums[i] - med)  ; 
        }
        return cnt ; 
    }
};