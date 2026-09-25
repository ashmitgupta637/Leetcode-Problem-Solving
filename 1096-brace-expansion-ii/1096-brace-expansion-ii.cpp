class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<set<string>> stk;
        vector<char> ops;
        
        auto combine = [](set<string>& s1, const set<string>& s2, char op) {
            if (op == ',') {
                s1.insert(s2.begin(), s2.end());
            } else if (op == '.') {
                set<string> res;
                for (const string& a : s1) {
                    for (const string& b : s2) {
                        res.insert(a + b);
                    }
                }
                s1 = move(res);
            }
        };

        auto evaluate_top = [&]() {
            set<string> s2 = stk.back(); stk.pop_back();
            set<string> s1 = stk.back(); stk.pop_back();
            char op = ops.back(); ops.pop_back();
            combine(s1, s2, op);
            stk.push_back(s1);
        };

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (i > 0) {
                char prev = expression[i - 1];
                if ((prev == '}' || isalpha(prev)) && (c == '{' || isalpha(c))) {
                    while (!ops.empty() && ops.back() == '.') {
                        evaluate_top();
                    }
                    ops.push_back('.');
                }
            }

            if (isalpha(c)) {
                stk.push_back({string(1, c)});
            } else if (c == '{') {
                ops.push_back('{');
            } else if (c == ',') {
                while (!ops.empty() && ops.back() != '{') {
                    evaluate_top();
                }
                ops.push_back(',');
            } else if (c == '}') {
                while (!ops.empty() && ops.back() != '{') {
                    evaluate_top();
                }
                ops.pop_back();
            }
        }

        while (!ops.empty()) {
            evaluate_top();
        }

        return vector<string>(stk.back().begin(), stk.back().end());
    }
};