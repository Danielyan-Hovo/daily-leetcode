class Solution {
    public:
    int smallestRepunitDivByK(int k) {

        int remainder = 1 % k;

        for (int length = 1; length <= k; ++length) {

            if (remainder == 0) {
                return length;
            }

            remainder = (remainder * 10 + 1) % k;
        }

        return -1;
    }
};