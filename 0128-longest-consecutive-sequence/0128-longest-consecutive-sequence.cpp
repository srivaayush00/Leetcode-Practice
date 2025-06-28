class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> u;
        for(auto &x:nums){
            u.insert(x);
        }
        int cnt=0,ans=INT_MIN,prev=0;

        for(auto &x:u){
            if(u.find(x-1)==u.end()){
                int y=x+1;cnt=1;
                while(u.find(y)!=u.end()){
                    y++;cnt++;
                }
            }
            ans=max(ans,cnt);

        }
        if(ans==INT_MIN)return 0;
        return ans;
    }
};