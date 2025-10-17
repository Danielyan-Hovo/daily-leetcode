class Solution {
    public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();

        unordered_map memo;

        function dfs = [&](int index, int charMask, int canChange) {

            if (index >= n) {
                return 1;
            }

            long long stateKey = (long long)index << 32 | charMask << 1 | canChange;

            if (memo.count(stateKey)) {
                return memo[stateKey];
            }

            int currentCharBit = 1 << (s[index] - 'a');

            int newCharMask = charMask | currentCharBit;

            int maxPartitions;
            if (__builtin_popcount(newCharMask) > k) {

                maxPartitions = dfs(index + 1, currentCharBit, canChange) + 1;
            } else {

                maxPartitions = dfs(index + 1, newCharMask, canChange);
            }

            if (canChange) {

                for (int letter = 0; letter < 26; ++letter) {
                    int replacementCharBit = 1 << letter;
                    newCharMask = charMask | replacementCharBit;

                    if (__builtin_popcount(newCharMask) > k) {

                        maxPartitions = max(maxPartitions,
                        dfs(index + 1, replacementCharBit, 0) + 1);
                    } else {

                        maxPartitions = max(maxPartitions,
                        dfs(index + 1, newCharMask, 0));
                    }
                }
            }

            return memo[stateKey] = maxPartitions;
        };

        return dfs(0, 0, 1);
    }
};