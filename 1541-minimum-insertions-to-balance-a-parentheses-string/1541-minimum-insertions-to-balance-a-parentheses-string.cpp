class Solution {
public:
    int minInsertions(string& s) {
        int n = s.size();
        int count = 0;
        int open = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
                continue;
            }

            if (!open)
                count++;
            else
                open--;

            if (i == n - 1 || s[i + 1] != ')')
                count++;
            else
                i++;
        }

        return count + open * 2;
    }
};