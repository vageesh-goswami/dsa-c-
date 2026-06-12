#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 15: 3Sum
// Given an integer array nums of length n, find all unique triplets in the array
// that add up to 0.
// Return all the triplets in any order.

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) return result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // If the current number is positive, no triplet can sum to 0
        if (nums[i] > 0) break;

        int left = i + 1, right = nums.size() - 1;
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = threeSum(nums1);
    cout << "Test 1 - 3Sum:\n";
    for (auto& triplet : result1) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
    // Expected: [[-1, -1, 2], [-1, 0, 1]]

    // Test case 2
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> result2 = threeSum(nums2);
    cout << "Test 2 - 3Sum:\n";
    for (auto& triplet : result2) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
    // Expected: (empty)

    // Test case 3
    vector<int> nums3 = {-2, 0, 1, 1, 2};
    vector<vector<int>> result3 = threeSum(nums3);
    cout << "Test 3 - 3Sum:\n";
    for (auto& triplet : result3) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
    // Expected: [[-2, 0, 2], [-2, 1, 1]]

    return 0;
}
