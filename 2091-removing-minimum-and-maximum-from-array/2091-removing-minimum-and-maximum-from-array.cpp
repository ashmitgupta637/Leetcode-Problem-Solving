class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int mini_index = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi_index = max_element(nums.begin(), nums.end()) - nums.begin();

        int k = min(mini_index, maxi_index);
        int j = max(mini_index, maxi_index);

        return min({
            j + 1,                 
            n - k,                 
            (k + 1) + (n - j)     
        });
    }
};