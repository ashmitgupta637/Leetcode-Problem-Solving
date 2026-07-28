class Solution {
public:
    int func(vector<int> & nums , int mid) {
        int stu = 1 ; 
        int x = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++) {
            if(x + nums[i] <= mid) {
                x += nums[i] ; 
            }else{
                stu++ ; 
                x = nums[i] ; 
            }
        }
        return stu ; 
    }
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()  < k) return -1 ; 

        int low = *max_element(nums.begin() , nums.end()) ; 
        int high = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++) {
            high += nums[i] ; 
        }
         
        while(low <= high) {
            int mid = low+  (high - low )/2; 

            int nostu = func(nums , mid) ; 
            if(nostu > k) low = mid+1 ;  
            else {
                high = mid-1 ; 
            }
        }
        return low ; 
    }
};