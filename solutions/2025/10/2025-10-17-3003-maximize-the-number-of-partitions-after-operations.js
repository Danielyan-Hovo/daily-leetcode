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

1#lang racket
2
3(define (binary-search arr target)
4  (let search ([l 0]
5               [r (sub1 (vector-length arr))])
6    ;; <= because left and right could point to the same element, < would miss it
7    (if (<= l r)
8        (let* ([m (quotient (+ l r) 2)]
9               [v (vector-ref arr m)])
10          (cond
11            ;; found target, return its index
12            [(= v target) m]
13            ;; middle less than target, discard left half by making left search boundary `m + 1`
14            [(< v target) (search (add1 m) r)]
15            ;; middle greater than target, discard right half by making right search boundary `m - 1`
16            [else (search l (sub1 r))]))
17        ;; if we get here we didn't hit above guard so we didn't find target
18        -1)))
19
20(define arr (list->vector (map string->number (string-split (read-line)))))
21(define target (string->number (read-line)))
22(define res (binary-search arr target))
23(displayln res)
24