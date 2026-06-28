class Solution {
public:
    int numSubarraysWithSumm(vector<int>& nums, int goal) {
        if(goal < 0) {
            return  0  ;
        }
        int left = 0  ; 
        int right  = 0  ; 
        int cnt = 0  ; 
        int sum = 0 ; 
        while(right < nums.size() ) {
            sum += nums[right]  ;
            while(sum > goal) {
                sum = sum- nums[left] ; 
                left++  ;
            }
            cnt = cnt + (right-left +1 ) ; 

            right++ ; 
        }
        return cnt ; 
    }
    int numSubarraysWithSum(vector<int>& nums, int goal){
        int x = numSubarraysWithSumm(nums, goal)  ; 
        int y   =numSubarraysWithSumm( nums, goal-1); 
        int sum = x-y ;    
        return sum  ; 
    }
};