class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = 0;
        int n2 = 0;
        int count = 0;

        int s = nums1.size() + nums2.size();

        int m1 = 0;
        int m2 = 0;

        while (count <= s / 2) {

            int current;

            // nums1 is exhausted
            if (n1 >= nums1.size()) {
                current = nums2[n2++];
            }

            // nums2 is exhausted
            else if (n2 >= nums2.size()) {
                current = nums1[n1++];
            }

            // Take smaller element
            else if (nums1[n1] <= nums2[n2]) {
                current = nums1[n1++];
            }

            else {
                current = nums2[n2++];
            }

            // Previous median
            if (count == s / 2 - 1) {
                m1 = current;
            }

            // Current median
            if (count == s / 2) {
                m2 = current;
            }

            count++;
        }

        if (s % 2 == 0) {
            return (m1 + m2) / 2.0;
        }

        return m2;
    }
};