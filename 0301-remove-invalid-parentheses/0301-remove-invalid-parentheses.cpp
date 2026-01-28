class Solution {
private:
    unordered_set<string> vis;
    int getMin(string s) {
        stack<char> st;
        for (auto& x : s) {
            if (x == '(') {
                st.push(x);
            } else if(x==')') {
                if(st.empty()){
                    st.push(x);
                }
                else if (st.top() == '(') {
                    st.pop();
                } else {
                    st.push(x);
                }
            }
        }
        return st.size();
    }
    void solve(string s, int minRemovalAllowed, set<string> &st){
        if(vis.find(s)!=vis.end()){
            return;
        }else{
            vis.insert(s);
        }
        if(minRemovalAllowed < 0){
            return;
        }
        if(minRemovalAllowed == 0){
            int minRemovalsNow = getMin(s);
            if(minRemovalsNow == 0){
                st.insert(s);
            }
            return;
        }
        for(int i=0;i<s.size();i++){
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right, minRemovalAllowed-1, st);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int minRemovals = getMin(s);
        vector<string> ans; 
        set<string> st;

        solve(s, minRemovals, st);

        for(auto &x:st){
            ans.push_back(x);
        }

        return ans;
    }
};