class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for (auto& it : knowledge)
            m[it[0]] = it[1];

        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '(') {
                ans.push_back(s[i]);
                continue;
            }
            i++;
            string key = "";
            while (s[i] != ')')
                key.push_back(s[i++]);

            if (m.find(key) == m.end())
                ans.push_back('?');
            else
                ans += m[key];
        }

        return ans;
    }
};