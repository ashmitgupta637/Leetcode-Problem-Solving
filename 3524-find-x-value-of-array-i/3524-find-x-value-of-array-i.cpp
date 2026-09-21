class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> prev_dp(k, 0);

        for (int num : nums) {
            vector<long long> curr_dp(k, 0);
            int rem = num % k;

           
            curr_dp[rem]++;

            
            for (int r = 0; r < k; ++r) {
                if (prev_dp[r] > 0) {
                    int new_rem = (r * rem) % k;
                    curr_dp[new_rem] += prev_dp[r];
                }
            }

            
            for (int r = 0; r < k; ++r) {
                result[r] += curr_dp[r];
            }

            prev_dp = move(curr_dp);
        }

        return result;
    }
};