class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        int left = 0;
        int cnt = 0;
        int lens = INT_MAX;

        
        for (int right = 0; right < n; right++) {
            
            if (s[right] == '1') {
                cnt++;
            }

            while (cnt == k) {
                lens = min(lens, right - left + 1);
                if (s[left] == '1') {
                    cnt--;
                }
                
                left++;
            }
        }
        if (lens == INT_MAX) {
            return "";
        }
        int cnt1 = 0;
        string ans = "";

        for (int i = 0; i < lens; i++) {
            if (s[i] == '1') {
                cnt1++;
            }
        }

       
        if (cnt1 == k) {
            ans = s.substr(0, lens);
        }
        for (int right = lens; right < n; right++) {
            if (s[right - lens] == '1') {
                cnt1--;
            }

            if (s[right] == '1') {
                cnt1++;
            }

            if (cnt1 == k) {
                string curr = s.substr(right - lens + 1, lens);

                if (ans == "" || curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};