class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0, t = 0;
        for (auto& c : s)
            maxi = max(maxi, (c == '(' ? ++t : (c == ')' ? --t : 0)));
        return maxi;
    }
};