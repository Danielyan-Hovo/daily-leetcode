// LeetCode Problem 3003: Maximize the Number of Partitions After Operations
// Difficulty: Hard
// Topics: String, Dynamic Programming, Bit Manipulation, Bitmask
// 
// Solution scraped from: https://algo.monster/liteproblems/3003
// Date: 2025-10-17
//
// Problem Description:
// <p>You are given a string <code>s</code> and an integer <code>k</code>.</p>

<p>First, you are allowed to change <strong>at most</strong> <strong>one</strong> index in <code>s</code> to another lowerc...
//

1class Solution {
2public:
3    int maxPartitionsAfterOperations(string s, int k) {
4        int n = s.size();
5        // Memoization map: key = (index << 32) | (charMask << 1) | canChange
6        unordered_map<long long, int> memo;
7      
8        // DFS function to find maximum partitions
9        // Parameters:
10        // - index: current position in string
11        // - charMask: bitmask representing distinct characters in current partition
12        // - canChange: flag indicating if we can still change one character (1 = yes, 0 = no)
13        function<int(int, int, int)> dfs = [&](int index, int charMask, int canChange) {
14            // Base case: reached end of string, count last partition
15            if (index >= n) {
16                return 1;
17            }
18          
19            // Create unique key for memoization
20            long long stateKey = (long long)index << 32 | charMask << 1 | canChange;
21          
22            // Return memoized result if exists
23            if (memo.count(stateKey)) {
24                return memo[stateKey];
25            }
26          
27            // Get bitmask for current character
28            int currentCharBit = 1 << (s[index] - 'a');
29          
30            // Calculate new character mask if we add current character
31            int newCharMask = charMask | currentCharBit;
32          
33            // Calculate result without changing current character
34            int maxPartitions;
35            if (__builtin_popcount(newCharMask) > k) {
36                // Too many distinct characters, start new partition
37                maxPartitions = dfs(index + 1, currentCharBit, canChange) + 1;
38            } else {
39                // Continue with current partition
40                maxPartitions = dfs(index + 1, newCharMask, canChange);
41            }
42          
43            // Try changing current character if we still have the option
44            if (canChange) {
45                // Try replacing current character with each letter 'a' to 'z'
46                for (int letter = 0; letter < 26; ++letter) {
47                    int replacementCharBit = 1 << letter;
48                    newCharMask = charMask | replacementCharBit;
49                  
50                    if (__builtin_popcount(newCharMask) > k) {
51                        // Too many distinct characters, start new partition
52                        maxPartitions = max(maxPartitions, 
53                                          dfs(index + 1, replacementCharBit, 0) + 1);
54                    } else {
55                        // Continue with current partition
56                        maxPartitions = max(maxPartitions, 
57                                          dfs(index + 1, newCharMask, 0));
58                    }
59                }
60            }
61          
62            // Memoize and return result
63            return memo[stateKey] = maxPartitions;
64        };
65      
66        // Start DFS from index 0, empty character mask, with ability to change one character
67        return dfs(0, 0, 1);
68    }
69};
70