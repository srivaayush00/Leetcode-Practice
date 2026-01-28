class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, minBalance = INT_MAX;
        for (auto& x : s) {
            if (x == '[') {
                balance++;
            } else {
                balance--;
            }
            minBalance = min(balance, minBalance);
        }
        return (abs(minBalance) + 1) / 2;
    }
};