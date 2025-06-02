class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int ans = 0, end = INT_MIN, n = points.size();
        for(int i=0;i<n;i++){
            if(points[i][0] > end){
                end = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};