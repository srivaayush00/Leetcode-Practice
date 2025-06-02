class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> ans;
        sort(interval.begin(),interval.end());
        ans.push_back(interval[0]);
        int j=0;
        int n=interval.size();
        for(int i=1;i<n;i++)
        {
            if(ans[j][1]>=interval[i][0])
                ans[j][1]=max(ans[j][1],interval[i][1]);
            else
            {
                j++;
                ans.push_back(interval[i]);
            }
        }
        return ans;
//         int p=0;
        
//         bool flag=true;
//         while(flag)
//         {
//             sort(invl.begin(),invl.end());
//             int n=invl.size();
//             cout<<n<<" "<<flag<<endl;
//             int p=0;
//             ans.clear();
//             flag=false;
//             for(int i=1;i<n;i=i+2)
//             {
//                 vector<int> ins=invl[i];
//                 vector<int> pre=invl[i-1];

//                 if(ins[0]<=pre[1])
//                 {                    
//                     ans.push_back({min(pre[0],ins[0]),max(pre[1],ins[1])});
//                     flag=true;

//                 }
//                 else
//                 {
//                     ans.push_back(pre);
//                     // ans.push_back(ins);
//                     i--;
//                 }
//                 p+=2;

//             }
//             // if(p!=n){
//             //     cout<<p<<endl;
//             //     ans.push_back(invl[n-1]);
//             // }
//             invl.clear();
//             invl=ans;
//         }
        // return ans;
    }
};