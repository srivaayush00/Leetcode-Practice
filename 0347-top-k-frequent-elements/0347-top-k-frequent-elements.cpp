class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        for(auto &x: nums)
            mp[x]++;
        
        vector<pair<int,int>> pq;
        for(auto &x:mp)
            pq.push_back({x.second,x.first});
        
        sort(pq.begin(), pq.end());
        reverse(pq.begin(), pq.end());
        int i = 0;
        while(k--)
        {
            ans.push_back(pq[i].second);
            i++;
            // pq.pop_();
        }
        return ans;
    }
};