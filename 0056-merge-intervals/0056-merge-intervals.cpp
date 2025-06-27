class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end());
        vector<vector<int>> ans;

        ans.push_back(interval[0]);
        int n = interval.size();
        int j = 0;
        for(int i=1;i<n;i++){
            if(interval[i][0] <= ans[j][1]){
                ans[j][1] = max(ans[j][1],interval [i][1]);
            }
            else{
                j++;
                ans.push_back(interval[i]);
            }
        }
        return ans;
        
    }
};