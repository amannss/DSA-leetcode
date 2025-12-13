class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
             int n = code.size();

        // Define business line priority
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> valid;  // {priority, code}

        for (int i = 0; i < n; i++) {

            // Check isActive
            if (!isActive[i]) continue;

            // Check businessLine
            if (priority.find(businessLine[i]) == priority.end())
                continue;

            // Check code validity
            if (code[i].empty()) continue;

            bool ok = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            valid.push_back({priority[businessLine[i]], code[i]});
        }

        // Sort by businessLine priority, then by code
        sort(valid.begin(), valid.end(), [](auto &a, auto &b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
        });

        // Extract result
        vector<string> result;
        for (auto &p : valid) {
            result.push_back(p.second);
        }

        return result;
    }
};