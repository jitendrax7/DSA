class Solution {
public:
    char lastchar;
    string ans = "";
    bool solve(string& curr, string& target, vector<int>& freq, int i,
               bool isgreater) {
        if (i == target.size() / 2) {
            string temp = curr;
            if (target.size() % 2)
                temp.push_back(lastchar);
            reverse(temp.begin(), temp.end());
            string res = curr + temp;
            if (res > target) {
                ans = res;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0)
                continue;
            if (!isgreater && ch < target[i])
                continue;
            curr.push_back(ch);
            freq[ch - 'a']--;
            bool greater = isgreater || ch > target[i];
            if (solve(curr, target, freq, i + 1, greater))
                return true;
            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        ans = "";
        lastchar = 0;
        vector<int> freq(26, 0);
        for (auto& it : s)
            freq[it - 'a']++;
        int n = s.size();
        int ones = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                ones++;
            if (freq[i] % 2)
                lastchar = i + 'a';
            freq[i] /= 2;
        }
        if (ones > 1)
            return "";
        string curr = "";
        solve(curr, target, freq, 0, false);
        return ans;
    }
};