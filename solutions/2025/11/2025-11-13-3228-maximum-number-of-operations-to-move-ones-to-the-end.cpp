class Solution {
    public:
    int maxOperations(string s) {
        int totalOperations = 0;
        int onesCount = 0;
        int stringLength = s.size();

        for (int i = 0; i < stringLength; ++i) {
            if (s[i] == '1') {

                ++onesCount;
            } else if (i > 0 && s[i - 1] == '1') {

                totalOperations += onesCount;
            }
        }

        return totalOperations;
    }
};