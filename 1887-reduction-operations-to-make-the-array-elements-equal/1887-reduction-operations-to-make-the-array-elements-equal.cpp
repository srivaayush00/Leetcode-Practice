class Solution {
public:
    int reductionOperations(vector<int>& a) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        int ans = 0, n = a.size();

        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                ans+=i;
            }
        }

        return ans;
    }
};
