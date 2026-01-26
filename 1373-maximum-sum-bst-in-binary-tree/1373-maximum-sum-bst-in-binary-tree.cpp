/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/* BRUTE FORCE SOLUTION!!
class Solution {

    typedef long long ll;

private:
    bool isBst(TreeNode* node, ll minVal, ll maxVal) {
        if (node == NULL) {
            return true;
        }
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        return isBst(node->left, minVal, node->val) &&
               isBst(node->right, node->val, maxVal);
    }

private:
    int sumTree(TreeNode* node) {
        if (node == NULL)
            return 0;
        return node->val + sumTree(node->left) + sumTree(node->right);
    }

private:
    int findLargest(TreeNode* node) {
        if (node == NULL)
            return 0;

        int curr = 0;
        if (isBst(node, LLONG_MIN, LLONG_MAX)) {
            curr = sumTree(node);
        }

        int left = findLargest(node->left);
        int right = findLargest(node->right);

        return max(curr, max(left, right));
    }

public:
    int maxSumBST(TreeNode* root) {
        int ans = max(0, findLargest(root));
        return ans;
    }
};
*/

typedef long long ll;

struct Info {
    bool isBst;
    int size;
    ll minVal;
    ll maxVal;
    ll sum;
};

class Solution {
    typedef long long ll;
    ll ans = 0ll;

private:
    Info findLargest(TreeNode* node) {
        if (node == NULL) {
            return {true, 0, LLONG_MAX, LLONG_MIN, 0ll};
        }

        Info leftInfo = findLargest(node->left);
        Info rightInfo = findLargest(node->right);

        Info curr;

        if (leftInfo.isBst && rightInfo.isBst && leftInfo.maxVal < node->val &&
            rightInfo.minVal > node->val) {
            curr.isBst = true;
            curr.size = 1 + leftInfo.size + rightInfo.size;
            curr.minVal = min((ll)node->val, leftInfo.minVal);
            curr.maxVal = max((ll)node->val, rightInfo.maxVal);
            curr.sum = node->val + leftInfo.sum + rightInfo.sum;

            ans = max(ans, curr.sum);
        } else {
            curr.isBst = false;
            curr.size = 0;
        }
        return curr;
    }

public:
    int maxSumBST(TreeNode* root) {
        findLargest(root);
        return ans;
    }
};