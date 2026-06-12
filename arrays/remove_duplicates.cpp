#include <iostream>
#include <vector>
using namespace std;

// LeetCode 26: Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates
// in-place such that each unique element appears only once.
// Return the number of unique elements k. Modify nums so that the first k elements
// contain the unique elements in order.

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int k = 1; // At least one unique element
    for (int i = 1; i < (int)nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    // Test case 1
    vector<int> nums1 = {1, 1, 2};
    int k1 = removeDuplicates(nums1);
    cout << "Test 1 - Remove Duplicates, k = " << k1 << ", array: ";
    for (int i = 0; i < k1; i++) cout << nums1[i] << " ";
    cout << "\n";

    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = removeDuplicates(nums2);
    cout << "Test 2 - Remove Duplicates, k = " << k2 << ", array: ";
    for (int i = 0; i < k2; i++) cout << nums2[i] << " ";
    cout << "\n";

    // Test case 3
    vector<int> nums3 = {1};
    int k3 = removeDuplicates(nums3);
    cout << "Test 3 - Remove Duplicates, k = " << k3 << ", array: ";
    for (int i = 0; i < k3; i++) cout << nums3[i] << " ";
    cout << "\n";

    return 0;
}
