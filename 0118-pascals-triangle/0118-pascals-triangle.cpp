class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        int nm = 1;
        for (int i = 0; i < n; i++) {
            ans[i].resize(i + 1);
            ans[i][0] = 1;
            for (int j = 1; j < i; j++)
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            ans[i][i] = 1;
        }
        return ans;
    }
};