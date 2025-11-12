class Solution {
    public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int onesCount = 0;
        for (int num : nums) {
            if (num == 1) {
                ++onesCount;
            }
        }

        if (onesCount > 0) {
            return n - onesCount;
        }

        int minLength = n + 1;
        for (int i = 0; i < n; ++i) {
            int currentGcd = 0;
            for (int j = i; j < n; ++j) {

                currentGcd = gcd(currentGcd, nums[j]);

                if (currentGcd == 1) {
                    minLength = min(minLength, j - i + 1);
                    break;
                }
            }
        }

        if (minLength > n) {
            return -1;
        }

        return (minLength - 1) + (n - 1);
    }
};