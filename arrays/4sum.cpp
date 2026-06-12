#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 18: 4Sum
// Given an array nums of n integers and an integer target, return all unique quadruplets
// in the array that add up to the target.
// Return all the quadruplets in any order.

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4) return result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; i++) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Optimization: if the smallest possible sum is greater than target, break
        if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;

        // Optimization: if the largest possible sum is less than target, continue
        if ((long long)nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;

        for (int j = i + 1; j < nums.size() - 2; j++) {
            // Skip duplicates for the second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // Optimization: if the smallest possible sum with j is greater than target, break
            if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;

            // Optimization: if the largest possible sum with j is less than target, continue
            if ((long long)nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) continue;

            int left = j + 1, right = nums.size() - 1;
            long long twoTarget = (long long)target - nums[i] - nums[j];

            while (left < right) {
                long long sum = (long long)nums[left] + nums[right];

                if (sum == twoTarget) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < twoTarget) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    // Test case 1
    vector<int> nums1 = {1000000000, 1000000000, 1000000000, 1000000000};
    int target1 = -294967296;
    vector<vector<int>> result1 = fourSum(nums1, target1);
    cout << "Test 1 - 4Sum:\n";
    for (auto& quad : result1) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]\n";
    }
    // Expected: (empty)

    // Test case 2
    vector<int> nums2 = {1000000000, 1000000000, 1000000000, 1000000000};
    int target2 = -294967296;
    vector<vector<int>> result2 = fourSum(nums2, target2);
    cout << "Test 2 - 4Sum:\n";
    for (auto& quad : result2) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]\n";
    }
    // Expected: (empty)

    // Test case 3
    vector<int> nums3 = {1000000000, 0, 0, 0, 0};
    int target3 = 0;
    vector<vector<int>> result3 = fourSum(nums3, target3);
    cout << "Test 3 - 4Sum:\n";
    for (auto& quad : result3) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]\n";
    }
    // Expected: (empty)

    // Test case 4
    vector<int> nums4 = {1, 0, -1, 0, -2, 2};
    int target4 = 0;
    vector<vector<int>> result4 = fourSum(nums4, target4);
    cout << "Test 4 - 4Sum:\n";
    for (auto& quad : result4) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]\n";
    }
    // Expected: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

    return 0;
}
