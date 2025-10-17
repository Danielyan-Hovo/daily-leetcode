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

1import java.util.Arrays;
2import java.util.List;
3import java.util.Scanner;
4import java.util.stream.Collectors;
5
6class Solution {
7    public static int binarySearch(List<Integer> arr, int target) {
8        int left = 0;
9        int right = arr.size() - 1;
10
11        while (left <= right) { // <= here because left and right could point to the same element, < would miss it
12            int mid = left + (right - left) / 2; // use `(right - left) / 2` to prevent `left + right` potential overflow
13            // found target, return its index
14            if (arr.get(mid) == target) return mid;
15            if (arr.get(mid) < target) {
16                // middle less than target, discard left half by making left search boundary `mid + 1`
17                left = mid + 1;
18            } else {
19                // middle greater than target, discard right half by making right search boundary `mid - 1`
20                right = mid - 1;
21            }
22        }
23        return -1; // if we get here we didn't hit above return so we didn't find target
24    }
25
26    public static List<String> splitWords(String s) {
27        return s.isEmpty() ? List.of() : Arrays.asList(s.split(" "));
28    }
29
30    public static void main(String[] args) {
31        Scanner scanner = new Scanner(System.in);
32        List<Integer> arr = splitWords(scanner.nextLine()).stream().map(Integer::parseInt).collect(Collectors.toList());
33        int target = Integer.parseInt(scanner.nextLine());
34        scanner.close();
35        int res = binarySearch(arr, target);
36        System.out.println(res);
37    }
38}
39