class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);

        int left = 0;
        int countAtLeastK = 0;
        long long ans = 0;

        for (int right = 0; right < n; right++) {
            int idx = s[right] - 'a';
            freq[idx]++;

            if (freq[idx] == k)
                countAtLeastK++;

            while (countAtLeastK > 0) {
                ans += (n - right);

                int lidx = s[left] - 'a';
                if (freq[lidx] == k)
                    countAtLeastK--;

                freq[lidx]--;
                left++;
            }
        }

        return ans;
    }
};