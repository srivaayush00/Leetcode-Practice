/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int cnt=0, ans=-1;
    void helper(TreeNode* root, int k){
        if(cnt>k || root==NULL){
            return;
        }
        helper(root->left, k);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        helper(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return ans;
    }
};