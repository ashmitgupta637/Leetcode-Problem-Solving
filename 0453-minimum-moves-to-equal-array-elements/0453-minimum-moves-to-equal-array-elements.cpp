class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt = 0 ; 
        int mini = *min_element(nums.begin() , nums.end()); 

        for(int i =0 ; i < nums.size() ; i++){
            if(nums[i] != mini){
                cnt += abs(mini - nums[i]) ; 
            }
        }

        return cnt ; 
    }
};