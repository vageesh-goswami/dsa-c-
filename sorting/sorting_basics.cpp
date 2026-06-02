#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Basic implementation: bubble sort.
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// Sample Problem 1: Merge sort.
// Approach: Divide array, sort halves recursively, then merge.
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < (int)left.size()) arr[k++] = left[i++];
    while (j < (int)right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Sample Problem 2: Quick sort.
// Approach: Partition around pivot and recurse on subarrays.
int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
}

// Sample Problem 3: Find k-th smallest.
// Approach: Sort then access index k-1 (simple baseline approach).
int kthSmallest(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

void printVector(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> a = {5, 1, 4, 2, 8};
    bubbleSort(a);
    cout << "Bubble sort: ";
    printVector(a);

    vector<int> b = {9, 3, 7, 1, 6};
    mergeSort(b, 0, (int)b.size() - 1);
    cout << "Merge sort: ";
    printVector(b);

    vector<int> c = {10, 80, 30, 90, 40, 50, 70};
    quickSort(c, 0, (int)c.size() - 1);
    cout << "Quick sort: ";
    printVector(c);

    cout << "3rd smallest in {7,2,9,4,1}: " << kthSmallest({7, 2, 9, 4, 1}, 3) << "\n";
    return 0;
}
