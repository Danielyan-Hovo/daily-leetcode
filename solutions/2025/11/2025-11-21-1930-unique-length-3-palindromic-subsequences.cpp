class Solution {
    public:
    int countPalindromicSubsequence(string s) {
        int result = 0;

        for (char ch = 'a'; ch <= 'z'; ++ch) {

            int firstIndex = s.find_first_of(ch);
            int lastIndex = s.find_last_of(ch);

            if (firstIndex == string::npos || firstIndex == lastIndex) {
                continue;
            }

            int characterMask = 0;

            for (int i = firstIndex + 1; i < lastIndex; ++i) {

                int charIndex = s[i] - 'a';

                if (((characterMask >> charIndex) & 1) == 0) {

                    characterMask |= (1 << charIndex);

                    ++result;
                }
            }
        }

        return result;
    }
};