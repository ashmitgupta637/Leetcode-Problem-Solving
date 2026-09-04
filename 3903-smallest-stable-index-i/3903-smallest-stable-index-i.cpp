class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(); 

        for(int i = 0 ; i < n ; i++){
            int mini = * max_element(nums.begin() , nums.begin()+ i+1) ; 
            int maxi = * min_element(nums.begin() + i, nums.end()) ; 

            if(mini-maxi <= k){
                return i ; 

            }
        }


        return -1 ; 
    }
};