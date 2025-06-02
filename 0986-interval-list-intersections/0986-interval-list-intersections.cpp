class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0,n=a.size(),m=b.size();

        while(i<n && j<m){
            int a1=a[i][0],b1=b[j][0],a2=a[i][1],b2=b[j][1];
            if(max(a1, b1) <= min(a2, b2)){
                ans.push_back({max(a1, b1), min(a2, b2)});
            }
            if(b2>a2){
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};