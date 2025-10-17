# LeetCode Problem 3003: Maximize the Number of Partitions After Operations
# Difficulty: Hard
# Topics: String, Dynamic Programming, Bit Manipulation, Bitmask
# 
# Solution scraped from: https://algo.monster/problems/binary_search_intro
# Date: 2025-10-17
#
# Problem Description:
# <p>You are given a string <code>s</code> and an integer <code>k</code>.</p>

<p>First, you are allowed to change <strong>at most</strong> <strong>one</strong> index in <code>s</code> to another lowerc...
#

1def binary_search(arr: list[int], target: int) -> int:
2    left, right = 0, len(arr) - 1
3    # <= because left and right could point to the same element, < would miss it
4    while left <= right:
5        # double slash for integer division in python 3,
6        # we don't have to worry about integer `left + right` overflow
7        # since python integers can be arbitrarily large
8        mid = (left + right) // 2
9        # found target, return its index
10        if arr[mid] == target:
11            return mid
12        # middle less than target, discard left half by making left search boundary `mid + 1`
13        if arr[mid] < target:
14            left = mid + 1
15        # middle greater than target, discard right half by making right search boundary `mid - 1`
16        else:
17            right = mid - 1
18    return -1  # if we get here we didn't hit above return so we didn't find target
19
20if __name__ == "__main__":
21    arr = [int(x) for x in input().split()]
22    target = int(input())
23    res = binary_search(arr, target)
24    print(res)
25