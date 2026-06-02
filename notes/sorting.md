# Sorting

## Key Concepts
- Reordering data for faster searching/processing.
- Stable sort keeps equal elements in original order.
- Comparison-based sorts have lower bound O(n log n).

## Time Complexity (Common Algorithms)
- Bubble sort: **O(n^2)**
- Merge sort: **O(n log n)**
- Quick sort (average): **O(n log n)**, worst: **O(n^2)**
- `std::sort` (introsort): roughly **O(n log n)**

## Common Patterns
- Sort + two pointers
- Custom comparator sorting
- Greedy after sorting
- K-th element via sorting / quickselect
