class Solution {
public:
    int subarrlessthank(vector<int> &nums , int k) {
        int left  = 0 ; 
        int cnt  = 0 ; 
        unordered_map<int ,int > freq ; 

        for(int right = 0 ; right < nums.size() ; right++) {
            freq[nums[right]]++ ; 
            while(freq.size() > k ) {
                freq[nums[left]]-- ; 
                if(freq[nums[left]] == 0 ){
                    freq.erase(nums[left]) ; 
                }
                left++ ; 
            }
            cnt = cnt +(right-left+1) ; 
        }
        return cnt ; 
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrlessthank(nums , k ) - subarrlessthank(nums , k-1 ); 
    }
};