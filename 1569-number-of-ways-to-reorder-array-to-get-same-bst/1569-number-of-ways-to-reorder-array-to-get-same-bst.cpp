class Solution {
    typedef long long ll;
    ll mod = 1e9 + 7;
    vector<vector<ll>> table;

private:
    ll dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return 1;
        }

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        ll left_res = dfs(left) % mod;
        ll right_res = dfs(right) % mod;

        int left_len = left.size(), right_len = right.size();

        return ((((table[n - 1][left_len] * left_res) % mod) *
                (right_res % mod))%mod);
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1);
        for (int i = 0; i < (n + 1); i++) {
            table[i] = vector<ll>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        ll ans = dfs(nums);
        return (ans - 1 + mod) % mod;
    }
};

/*
C(n-1, left) * ordering Left * ordering Right
C(n,r)=C(n−1,r−1)+C(n−1,r)
*/