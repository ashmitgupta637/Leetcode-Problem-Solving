#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, int> count;
        std::unordered_map<int, int> first;
        std::unordered_map<int, int> last;

        int degree = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];

            
            if (first.find(val) == first.end()) {
                first[val] = i;
            }

            
            last[val] = i;
            count[val]++;

            
            degree = std::max(degree, count[val]);
        }

        int min_length = nums.size();

        
        for (const auto& [val, freq] : count) {
            if (freq == degree) {
                int length = last[val] - first[val] + 1;
                min_length = std::min(min_length, length);
            }
        }

        return min_length;
    }
};