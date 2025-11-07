class Solution {
    public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        long diff[n + 1];
        memset(diff, 0, sizeof diff);

        for (int i = 0; i < n; ++i) {
            int leftBound = max(0, i - r);
            int rightBound = min(i + r, n - 1);
            diff[leftBound] += stations[i];
            diff[rightBound + 1] -= stations[i];
        }

        long prefixPower[n + 1];
        prefixPower[0] = diff[0];
        for (int i = 1; i < n + 1; ++i) {
            prefixPower[i] = prefixPower[i - 1] + diff[i];
        }

        auto canAchieveMinPower = [&](long targetPower, int availableStations) {

            long additionalDiff[n + 1];
            memset(additionalDiff, 0, sizeof additionalDiff);
            long additionalPower = 0;

            for (int i = 0; i < n; ++i) {

                additionalPower += additionalDiff[i];

                long currentPower = prefixPower[i] + additionalPower;
                long deficit = targetPower - currentPower;

                if (deficit > 0) {

                    if (availableStations < deficit) {
                        return false;
                    }

                    availableStations -= deficit;
                    int placementPos = min(i + r, n - 1);
                    int coverageLeft = max(0, placementPos - r);
                    int coverageRight = min(placementPos + r, n - 1);

                    additionalDiff[coverageLeft] += deficit;
                    additionalDiff[coverageRight + 1] -= deficit;
                    additionalPower += deficit;
                }
            }
            return true;
        };

        long left = 0;
        long right = 1e12;

        while (left < right) {
            long mid = (left + right + 1) >> 1;

            if (canAchieveMinPower(mid, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};