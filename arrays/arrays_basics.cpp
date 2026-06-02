#include <iostream>
#include <vector>
using namespace std;

// Basic implementation: linear search in an array.
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Sample Problem 1: Find maximum element.
// Approach: Single pass and keep track of current maximum.
int findMax(const vector<int>& arr) {
    if (arr.empty()) return -1;
    int mx = arr[0];
    for (int x : arr) mx = max(mx, x);
    return mx;
}

// Sample Problem 2: Move all zeros to end.
// Approach: Two-pointer style compaction, then fill remaining with zeros.
vector<int> moveZerosToEnd(vector<int> arr) {
    int insertPos = 0;
    for (int x : arr) {
        if (x != 0) arr[insertPos++] = x;
    }
    while (insertPos < (int)arr.size()) arr[insertPos++] = 0;
    return arr;
}

// Sample Problem 3: Prefix sum query [l, r].
// Approach: Build prefix array once, answer in O(1).
int rangeSum(const vector<int>& prefix, int l, int r) {
    return l == 0 ? prefix[r] : prefix[r] - prefix[l - 1];
}

int main() {
    vector<int> arr = {3, 0, 7, 0, 2, 9};
    cout << "Linear search (7): " << linearSearch(arr, 7) << "\n";
    cout << "Maximum: " << findMax(arr) << "\n";

    vector<int> moved = moveZerosToEnd(arr);
    cout << "Move zeros: ";
    for (int x : moved) cout << x << " ";
    cout << "\n";

    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) prefix[i] = prefix[i - 1] + nums[i];
    cout << "Range sum [1,3]: " << rangeSum(prefix, 1, 3) << "\n";
    return 0;
}
