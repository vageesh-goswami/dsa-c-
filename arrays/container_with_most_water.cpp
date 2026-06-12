#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 11: Container With Most Water
// Given an integer array height of length n, find two lines that together with the x-axis
// form a container that can hold the most water.
// Return the maximum area of water that can be contained.

int maxArea(vector<int>& height) {
    int maxWater = 0;
    int left = 0, right = height.size() - 1;

    while (left < right) {
        // Calculate the area between left and right pointers
        int width = right - left;
        int h = min(height[left], height[right]);
        int area = width * h;
        maxWater = max(maxWater, area);

        // Move the pointer pointing to the smaller height
        // because moving the larger pointer would only decrease the area
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    // Test case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result1 = maxArea(height1);
    cout << "Test 1 - Container With Most Water: " << result1 << "\n";
    // Expected: 49 (between indices 1 and 8, height=7, width=7, area=49)

    // Test case 2
    vector<int> height2 = {1, 1};
    int result2 = maxArea(height2);
    cout << "Test 2 - Container With Most Water: " << result2 << "\n";
    // Expected: 1

    // Test case 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    int result3 = maxArea(height3);
    cout << "Test 3 - Container With Most Water: " << result3 << "\n";
    // Expected: 16 (between indices 0 and 4, height=4, width=4, area=16)

    return 0;
}
