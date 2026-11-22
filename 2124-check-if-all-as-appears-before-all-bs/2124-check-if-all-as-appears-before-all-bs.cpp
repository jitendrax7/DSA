class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b')
                b++;
            else if (s[i] == 'a' && b > 0)
                return false;
        }

        return true;
    }
};