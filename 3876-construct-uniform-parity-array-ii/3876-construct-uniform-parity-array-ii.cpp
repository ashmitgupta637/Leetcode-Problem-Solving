/*
 * @lc app=leetcode id=3876 lang=cpp
 *
 * [3876] Construct Uniform Parity Array II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool parity = false;  // even = true, odd = false
        int n = nums1.size();

        int smallestElement = *min_element(nums1.begin(), nums1.end());

        if (smallestElement % 2 == 0)
            parity = true;   // even
        else
            parity = false;  // odd

        if (!parity) {
            for (int i = 0; i < n; i++) {
                if (nums1[i] != smallestElement) {
                    if (nums1[i] % 2 != 0) {
                        continue;
                    }
                    else if ((nums1[i] - smallestElement) >= 1 &&
                             (nums1[i] - smallestElement) % 2 != 0) {
                        continue;
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        if (parity) {
            for (int i = 0; i < n; i++) {
                if (nums1[i] != smallestElement) {
                    if (nums1[i] % 2 == 0) {
                        continue;
                    }
                    else if ((nums1[i] - smallestElement) >= 1 &&
                             (nums1[i] - smallestElement) % 2 == 0) {
                        continue;
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end
