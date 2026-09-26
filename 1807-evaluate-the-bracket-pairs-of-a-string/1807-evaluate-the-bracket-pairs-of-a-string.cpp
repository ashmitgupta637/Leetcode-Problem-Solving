class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        int i = 0;
        int n = s.length();
        while (i < n) {
            if (s[i] == '(') {
                int j = i;
                while (j < n && s[j] != ')') {
                    j++;
                }
                string subs = s.substr(i, j - i + 1);
                string wo_bracket = s.substr(i + 1, j - i - 1);
                int len = j - i + 1;
                
                if (mp.find(wo_bracket) != mp.end()) {
                    s.replace(i, len, mp[wo_bracket]);
                    i += mp[wo_bracket].length();
                } else {
                    s.replace(i, len, "?");
                    i += 1;
                }
                n = s.length();
            } else {
                i++;
            }
        }

        return s;
    }
};