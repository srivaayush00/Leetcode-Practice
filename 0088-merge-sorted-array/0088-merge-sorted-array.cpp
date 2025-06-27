class Solution {
public:
    void merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
        int p1 = m - 1;    // Pointer for end of nums1
        int p2 = n - 1;    // Pointer for end of nums2
        int p = m + n - 1; // Pointer for placement in nums1

        // Merge from the back to avoid overwriting
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                --p1;
            } else {
                nums1[p] = nums2[p2];
                --p2;
            }
            --p;
        }
    }
};