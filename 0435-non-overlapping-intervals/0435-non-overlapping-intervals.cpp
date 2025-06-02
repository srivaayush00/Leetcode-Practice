class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int ans = 0, end = INT_MIN, n = intervals.size();
        for(int i=0;i<n;i++){
            if(intervals[i][0] >= end){
                end = intervals[i][1];
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};