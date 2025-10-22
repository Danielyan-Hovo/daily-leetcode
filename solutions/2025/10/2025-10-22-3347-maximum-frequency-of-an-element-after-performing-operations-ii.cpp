class Solution {
    public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        unordered_map<int, int> frequency;

        map<int, int> rangeBoundaries;

        for (int num : nums) {

            frequency[num]++;

            rangeBoundaries[num];

            rangeBoundaries[num - k]++;

            rangeBoundaries[num + k + 1]--;
        }
        int maxResult = 0;
        int activeCount = 0;

        for (const auto& [position, delta] : rangeBoundaries) {

            activeCount += delta;

            maxResult = max(maxResult, min(activeCount, frequency[position] + numOperations));
        }
        return maxResult;
    }
};