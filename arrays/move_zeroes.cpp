#include <iostream>
#include <vector>
using namespace std;

// LeetCode 283: Move Zeroes
// Given an integer array nums, move all 0's to the end while maintaining the relative
// order of the non-zero elements.
// Modify nums in-place and do not return anything.

void moveZeroes(vector<int>& nums) {
    int insertPos = 0;

    // First pass: move all non-zero elements to the front
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != 0) {
            nums[insertPos] = nums[i];
            insertPos++;
        }
    }

    // Second pass: fill remaining positions with zeros
    while (insertPos < (int)nums.size()) {
        nums[insertPos] = 0;
        insertPos++;
    }
}

int main() {
    // Test case 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    cout << "Test 1 - Before: ";
    for (int x : nums1) cout << x << " ";
    cout << "\n";
    moveZeroes(nums1);
    cout << "After: ";
    for (int x : nums1) cout << x << " ";
    cout << "\n";

    // Test case 2
    vector<int> nums2 = {0};
    cout << "Test 2 - Before: ";
    for (int x : nums2) cout << x << " ";
    cout << "\n";
    moveZeroes(nums2);
    cout << "After: ";
    for (int x : nums2) cout << x << " ";
    cout << "\n";

    // Test case 3
    vector<int> nums3 = {1, 2, 3};
    cout << "Test 3 - Before: ";
    for (int x : nums3) cout << x << " ";
    cout << "\n";
    moveZeroes(nums3);
    cout << "After: ";
    for (int x : nums3) cout << x << " ";
    cout << "\n";

    return 0;
}
