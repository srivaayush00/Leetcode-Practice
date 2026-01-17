class Solution {
    typedef long long ll;
private:
    long long fun(ll a, ll b, ll c, ll d) {
        if (a >= c || b >= d)
            return 0;
        ll s = min(c - a, d - b);
        return (s * s);
    }

public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0ll;
        int n=bottomLeft.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll a = max((ll)bottomLeft[i][0], (ll)bottomLeft[j][0]);
                ll b = max((ll)bottomLeft[i][1], (ll)bottomLeft[j][1]);
                ll c = min((ll)topRight[i][0], (ll)topRight[j][0]);
                ll d = min((ll)topRight[i][1], (ll)topRight[j][1]);

                ans = max(ans, fun(a, b, c, d));
                
            }
        }

        return ans;
    }
};