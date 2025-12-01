class Solution {
    public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long left = 0, right = 0;
        for (int battery : batteries) {
            right += battery;
        }

        while (left < right) {

            long long mid = (left + right + 1) >> 1;

            long long totalCapacity = 0;
            for (int battery : batteries) {
                totalCapacity += min(static_cast<long long>(battery), mid);
            }

            if (totalCapacity >= n * mid) {

                left = mid;
            } else {

                right = mid - 1;
            }
        }

        return left;
    }
};