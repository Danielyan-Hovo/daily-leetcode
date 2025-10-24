class Solution {
    public:
    int nextBeautifulNumber(int n) {

        for (int candidate = n + 1;; ++candidate) {

            int digitFrequency[10] = {0};

            for (int temp = candidate; temp > 0; temp /= 10) {
                int digit = temp % 10;
                ++digitFrequency[digit];
            }

            bool isBeautiful = true;

            for (int temp = candidate; temp > 0; temp /= 10) {
                int digit = temp % 10;

                if (digit != digitFrequency[digit]) {
                    isBeautiful = false;
                    break;
                }
            }

            if (isBeautiful) {
                return candidate;
            }
        }
    }
};