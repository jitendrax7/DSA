class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    ll findPower(ll a, ll base) {
        if (base == 0)
            return 1;

        ll half = findPower(a, base / 2);
        ll res = (half * half) % MOD;
        if (base % 2 == 1) {
            res = (res * a) % MOD;
        }
        return res;
    }
    bool check(vector<int>& nums, int size, int base) {
        int n = nums.size();

        ll hash = 0;
        unordered_map<ll, int> m;
        ll p = findPower(base, size - 1);
        int i = 0;
        int j = 0;

        while (j < n) {
            hash = (hash * base + nums[j]) % MOD;

            if (j - i + 1 < size) {
                j++;
            } else {
                m[hash]++;
                hash = (hash - (p * nums[i]) % MOD + MOD) % MOD;
                i++;
                j++;
            }
        }

        for (auto& it : m) {
            if (it.second == 1)
                return true;
        }

        return 0;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int base = *max_element(nums.begin(), nums.end()) + 1;
        int res = n;

        int l = 1;
        int r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(nums, mid, base)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};