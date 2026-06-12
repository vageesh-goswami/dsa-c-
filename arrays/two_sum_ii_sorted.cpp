#include <iostream>
#include <vector>
using namespace std;

// LeetCode 167: Two Sum II (Input Array Is Sorted)
// Given an array of integers numbers that is already sorted in non-decreasing order,
// find two numbers that add up to a specific target number.
// Return the indices of the two numbers (1-indexed).

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1}; // 1-indexed
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {}; // Should not reach here if input is valid
}

int main() {
    // Test case 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(numbers1, target1);
    cout << "Test 1 - Two Sum II: [" << result1[0] << ", " << result1[1] << "]\n";

    // Test case 2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = twoSum(numbers2, target2);
    cout << "Test 2 - Two Sum II: [" << result2[0] << ", " << result2[1] << "]\n";

    // Test case 3
    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = twoSum(numbers3, target3);
    cout << "Test 3 - Two Sum II: [" << result3[0] << ", " << result3[1] << "]\n";

    return 0;
}
