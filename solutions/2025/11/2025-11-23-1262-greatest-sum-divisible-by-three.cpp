class Solution {
    public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        const int INF = 1 << 30;

        int dp[n + 1][3];

        dp[0][0] = 0;
        dp[0][1] = -INF;
        dp[0][2] = -INF;

        for (int i = 1; i <= n; ++i) {
            int currentNum = nums[i - 1];

            for (int remainder = 0; remainder < 3; ++remainder) {

                int excludeCurrent = dp[i - 1][remainder];

                int prevRemainder = (remainder - currentNum % 3 + 3) % 3;
                int includeCurrent = dp[i - 1][prevRemainder] + currentNum;

                dp[i][remainder] = max(excludeCurrent, includeCurrent);
            }
        }

        return dp[n][0];
    }
};