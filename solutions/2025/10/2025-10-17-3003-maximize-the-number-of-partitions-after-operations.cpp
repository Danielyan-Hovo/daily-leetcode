// LeetCode Problem 3003: Maximize the Number of Partitions After Operations
// Difficulty: Hard
// Topics: String, Dynamic Programming, Bit Manipulation, Bitmask
// 
// Solution scraped from: https://algo.monster/problems/binary_search_intro
// Date: 2025-10-17
//
// Problem Description:
// <p>You are given a string <code>s</code> and an integer <code>k</code>.</p>

<p>First, you are allowed to change <strong>at most</strong> <strong>one</strong> index in <code>s</code> to another lowerc...
//

1#include <algorithm>
2#include <iostream>
3#include <iterator>
4#include <limits>
5#include <sstream>
6#include <string>
7#include <vector>
8
9int binary_search(std::vector<int> arr, int target) {
10    int left = 0;
11    int right = arr.size() - 1;
12
13    while (left <= right) { // <= here because left and right could point to the same element, < would miss it
14        int mid = left + (right - left) / 2; // use `(right - left) / 2` to prevent `left + right` potential overflow
15        // found target, return its index
16        if (arr.at(mid) == target) return mid;
17        if (arr.at(mid) < target) {
18            // middle less than target, discard left half by making left search boundary `mid + 1`
19            left = mid + 1;
20        } else {
21            // middle greater than target, discard right half by making right search boundary `mid - 1`
22            right = mid - 1;
23        }
24    }
25    return -1; // if we get here we didn't hit above return so we didn't find target
26}
27
28template<typename T>
29std::vector<T> get_words() {
30    std::string line;
31    std::getline(std::cin, line);
32    std::istringstream ss{line};
33    ss >> std::boolalpha;
34    std::vector<T> v;
35    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
36    return v;
37}
38
39void ignore_line() {
40    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
41}
42
43int main() {
44    std::vector<int> arr = get_words<int>();
45    int target;
46    std::cin >> target;
47    ignore_line();
48    int res = binary_search(arr, target);
49    std::cout << res << '\n';
50}
51