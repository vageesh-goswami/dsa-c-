#include <iostream>
#include <vector>
using namespace std;

// LeetCode 88: Merge Sorted Array
// Given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two
// integers m and n representing the number of valid elements in nums1 and nums2.
// Merge nums2 into nums1 as one sorted array in-place.

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;        // Pointer for nums1's valid elements
    int p2 = n - 1;        // Pointer for nums2
    int p = m + n - 1;     // Pointer for the final position in nums1

    // Start from the end and compare elements
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    // If there are remaining elements in nums2, copy them
    // (no need to copy remaining nums1 elements as they are already in place)
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}

int main() {
    // Test case 1
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2_1 = {2, 5, 6};
    int m1 = 3, n1 = 3;
    cout << "Test 1 - Before merge: ";
    for (int x : nums1_1) cout << x << " ";
    cout << "\n";
    merge(nums1_1, m1, nums2_1, n1);
    cout << "After merge: ";
    for (int x : nums1_1) cout << x << " ";
    cout << "\n";

    // Test case 2
    vector<int> nums1_2 = {1};
    vector<int> nums2_2 = {};
    int m2 = 1, n2 = 0;
    cout << "Test 2 - Before merge: ";
    for (int x : nums1_2) cout << x << " ";
    cout << "\n";
    merge(nums1_2, m2, nums2_2, n2);
    cout << "After merge: ";
    for (int x : nums1_2) cout << x << " ";
    cout << "\n";

    // Test case 3
    vector<int> nums1_3 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2_3 = {1, 2, 3};
    int m3 = 3, n3 = 3;
    cout << "Test 3 - Before merge: ";
    for (int x : nums1_3) cout << x << " ";
    cout << "\n";
    merge(nums1_3, m3, nums2_3, n3);
    cout << "After merge: ";
    for (int x : nums1_3) cout << x << " ";
    cout << "\n";

    return 0;
}
